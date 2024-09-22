/**
 * @file HalTimer.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef HAL_HALTIMER_H_
#define HAL_HALTIMER_H_

void     Hal_timer_init(void);
uint32_t Hal_timer_get_1ms_counter(void);

#endif /* HAL_HALTIMER_H_ */