/**
 * @file stdio.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef LIB_STDIO_H_
#define LIB_STDIO_H_

#include "stdarg.h"

typedef enum utoa_t
{
    utoa_dec = 10,
    utoa_hex = 16,
} utoa_t;

uint32_t putstr(const char* s);
uint32_t debug_printf(const char* format, ...);
uint32_t vsprintf(char* buf, const char* format, va_list arg);
uint32_t utoa(char* buf, uint32_t val, utoa_t base);

#endif /* LIB_STDIO_H_ */