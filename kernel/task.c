/**
 * @file task.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "task.h"
#include "switch.h"

static KernelTcb_t* Scheduler_round_robin_algorithm(void);
static KernelTcb_t* Scheduler_priority_algorithm(void);

static KernelTcb_t sTask_list[MAX_TASK_NUM];
static uint32_t    sAllocated_tcb_index;
static uint32_t    sCurrent_tcb_index;

KernelTcb_t* gCurrent_tcb;
KernelTcb_t* gNext_tcb;

void Kernel_task_init(void)
{
    sAllocated_tcb_index    = 0;
    sCurrent_tcb_index      = 0;

    for(uint32_t i = 0; i < MAX_TASK_NUM; ++i)
    {
        sTask_list[i].stack_base=   (uint8_t*)(TASK_STACK_START +
                                    (i * USR_TASK_STACK_SIZE));
        sTask_list[i].sp        =   (uint32_t)sTask_list[i].stack_base +
                                    (USR_TASK_STACK_SIZE - 4); 
    
        sTask_list[i].sp       -=   (sizeof(KernelTaskContext_t));
        KernelTaskContext_t* ctx=   (KernelTaskContext_t*)sTask_list[i].sp;
        ctx->pc                 =   0;
        ctx->spsr               =   ARM_MODE_BIT_SYS;
    }

    return;
}
void Kernel_task_start(void)
{
    gNext_tcb = &sTask_list[sCurrent_tcb_index];
    Arch_Restore_context();
}
uint32_t Kernel_task_create(KernelTaskFunc_t startFunc, uint32_t priority)
{
    KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if(sAllocated_tcb_index > MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }

    new_tcb->priority = priority;

    KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
    ctx->pc = (uint32_t)startFunc;

    return (sAllocated_tcb_index - 1);
}
static KernelTcb_t* Scheduler_round_robin_algorithm(void)
{
    
    ++sCurrent_tcb_index;
    sCurrent_tcb_index %= sAllocated_tcb_index;

    return &sTask_list[sCurrent_tcb_index];
}
static KernelTcb_t* Scheduler_priority_algorithm(void)
{
    for(uint32_t i = 0;i < sAllocated_tcb_index; ++i)
    {
        KernelTcb_t* pNextTcb = &sTask_list[i];
        if(pNextTcb != pNextTcb)
        {
            if(pNextTcb->priority <= gCurrent_tcb->priority)
            {
                return pNextTcb;
            }
        }
    }
    
    return gCurrent_tcb;
}
void Kernel_task_scheduler(void)
{
    gCurrent_tcb = &sTask_list[sCurrent_tcb_index];
    gNext_tcb    = Scheduler_round_robin_algorithm();

    Arch_context_switching();

    return;
}