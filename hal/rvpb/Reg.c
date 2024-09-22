/**
 * @file Reg.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "stdint.h"
#include "Uart.h"
#include "Interrupt.h"
#include "Timer.h"


volatile PL011_t*   Uart    = (PL011_t*)UART_BASE_ADDRESS0;
volatile GicCput_t* GicCpu  = (GicCput_t*)GIC_CPU_BASE;
volatile GicDist_t* GicDist = (GicDist_t*)GIC_DIST_BASE;
volatile Timer_t*   Timer   = (Timer_t*)TIMER_CPU_BASE;
