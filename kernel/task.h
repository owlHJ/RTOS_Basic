/**
 * @file task.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef KERNEL_TASK_H_
#define KERNEL_TASK_H_

#include "stdint.h"
#include "stdbool.h"

#include "ARMv7AR.h"
#include "MemoryMap.h"
#include "switch.h"

#define NOT_ENOUGH_TASK_NUM 0xFFFFFFFF
#define USR_TASK_STACK_SIZE 0x100000
#define MAX_TASK_NUM        (TASK_STACK_SIZE/USR_TASK_STACK_SIZE)

typedef struct KernelTaskContext_t
{
    /* data */
    uint32_t spsr;
    uint32_t r0_r12[13];
    uint32_t pc;
}KernelTaskContext_t;
typedef struct KernelTcb_t
{
    /* data */
    uint32_t sp;
    uint32_t priority;
    uint8_t* stack_base;
}KernelTcb_t;
typedef void (*KernelTaskFunc_t)(void);
uint32_t Kernel_task_create(KernelTaskFunc_t startFunc, const uint32_t priority);
void        Kernel_task_init(void);
void        Kernel_task_start(void);
void        Kernel_task_scheduler(void);

#endif /* KERNEL_TASK_H_ */

