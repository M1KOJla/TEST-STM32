#ifndef BUTTON_PERIPH_H
#define BUTTON_PERIPH_H

#include "stm32f1xx.h"
#define SYSCLK_FREQ  8000000U							//макрос системной частоты МК

void PORTA_init (void);								//прототип функции инициализации порта PORTA
void TIM2_init (void);							        //прототип функции инициализации TIM2
uint8_t read_button_state (void);                                               //прототип функции read_button_state
extern void button_press_tracking_irq (void);

#endif 