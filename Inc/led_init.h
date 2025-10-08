#ifndef LED_INIT_H
#define LED_INIT_H

#include "stm32f1xx.h"
#define SYSCLK_FREQ  8000000U							//макрос системной частоты МК

void PORTB_init (void);							        //прототип функции инициализации PORTB PIN2&PIN5
void TIM3_init (void);

#endif 