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

void Kernel_yield(void)
{
    Kernel_task_scheduler();
}
void Kernel_start(void)
{
    Kernel_task_start();
}