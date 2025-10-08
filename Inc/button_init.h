#ifndef BUTTON_INIT_H
#define BUTTON_INIT_H

#include "stm32f1xx.h"
#define SYSCLK_FREQ  8000000U							//макрос системной частоты МК

void PORTA_init (void);								//прототип функции инициализации порта PORTA
void TIM2_init (void);							        //прототип функции инициализации TIM2

#endif 