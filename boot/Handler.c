/**
 * @file Handler.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "stdbool.h"
#include "stdint.h"
#include "HalInterrupt.h"

 __attribute__ ((interrupt ("IRQ"))) void Irq_handler(void)
{
    Hal_interrupt_run_handler();
}
 __attribute__ ((interrupt ("FIQ"))) void Fiq_handler(void)
{
    while(true);
}
