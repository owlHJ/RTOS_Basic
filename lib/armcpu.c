/**
 * @file armcpu.c
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#include "armcpu.h"

void enable_irq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS r0, cpsr");
    __asm__ ("BIC r1, r0, #0x80");
    __asm__ ("MSR cpsr, r1");
    __asm__ ("POP {r0, r1}");

    return;
}
void enable_fiq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS r0, cpsr");
    __asm__ ("BIC r1, r0, #0x40");
    __asm__ ("MSR cpsr, r1");
    __asm__ ("POP {r0, r1}");

    return;
}
void disable_irq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS r0, cpsr");
    __asm__ ("ORR r1, r0, #0x80");
    __asm__ ("MSR cpsr, r1");
    __asm__ ("POP {r0, r1}");

    return;
}
void disable_fiq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS r0, cpsr");
    __asm__ ("ORR r1, r0, #0x40");
    __asm__ ("MSR cpsr, r1");
    __asm__ ("POP {r0, r1}");

    return;
}