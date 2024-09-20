/**
 * @file HalUart.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_
#include "stdint.h"

void    Hal_uart_init(void);
void    Hal_uart_put_char(uint8_t ch);
// uint8_t Hal_uart_get_char(void);

#endif /* HAL_HALUART_H_ */
