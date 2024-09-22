/**
 * @file armcpu.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef LIB_ARMCPU_H_
#define LIB_ARMCPU_H_

void enable_irq(void);
void enable_fiq(void);
void disable_irq(void);
void disable_fiq(void);

#endif /* LIB_ARMCPU_H_*/