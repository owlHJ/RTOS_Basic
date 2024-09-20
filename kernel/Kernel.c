/**
 * @file Kernel.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "Kernel.h"
#include "event.h"
#include "memio.h"

void Kernel_yield(void)
{
    Kernel_task_scheduler();
}
void Kernel_start(void)
{
    Kernel_task_start();
}
void Kernel_send_events(uint32_t event_list)
{
    KernelEventFlag_t sending_event = KernelEventFlag_Empty;

    for (uint32_t i = 0 ; i < 32 ; i++)
    {
        if ((event_list >> i) & 1)
        {
            SET_BIT(sending_event, i);
            Kernel_event_flag_set(sending_event);
        }
    }
}
KernelEventFlag_t Kernel_wait_events(uint32_t waiting_list)
{
    KernelEventFlag_t waiting_event = KernelEventFlag_Empty;

    for (uint32_t i = 0 ; i < 32 ; i++)
    {
        if ((waiting_list >> i) & 1)
        {
            SET_BIT(waiting_event, i);

            if (Kernel_event_flag_check(waiting_event))
            {
                return waiting_event;
            }
        }
    }

    return KernelEventFlag_Empty;
}