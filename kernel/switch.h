/**
 * @file switch.h
 * @author hjkim <rlaguswns901@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef LIB_CORTEXM_SWITCH_H_
#define LIB_CORTEXM_SWITCH_H_

void Arch_start(void);
void Arch_context_switching(void);
void Arch_Restore_context(void);

#endif /* LIB_CORTEXM_SWITCH_H_ */
