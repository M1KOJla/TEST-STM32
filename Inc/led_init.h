#ifndef LED_INIT_H
#define LED_INIT_H

#include "stm32f1xx.h"
#define SYSCLK_FREQ  8000000U							//макрос системной частоты МК

void LED_PORT_init (void);							//прототип функции инициализации PORTB PIN2&PIN5
void LED_TIM_init (void);                                                       //прототип функции инициализации TIM3

uint8_t read_LED_state (void);                                                  //прототип функции чтение состояния LED
void LED_off (void);                                                            //прототип функции LED_off
void LED_on (void);                                                             //прототип функции LED_on
void blinc_start (void);                                                        //прототип функции blinc_start
void blinc_stop (void);                                                         //прототип функции blinc_stop

#endif 