/**
 * @file event.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "stdint.h"
#include "stdbool.h"

#include "stdio.h"
#include "event.h"

static uint32_t sEventFlag;

void Kernel_event_flag_init(void)
{
    sEventFlag = 0;
}
void Kernel_event_flag_set(KernelEventFlag_t event)
{
    sEventFlag |= (uint32_t)event;
}
void Kernel_event_flag_clear(KernelEventFlag_t event)
{
    sEventFlag &= ~((uint32_t)event);
}
bool Kernel_event_flag_check(KernelEventFlag_t event)
{
    bool bRet = false;

    if(sEventFlag * (uint32_t)event)
    {
        Kernel_event_flag_clear(event);
        bRet = true;
    }

    return bRet;
}