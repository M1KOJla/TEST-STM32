#ifndef LED_PROC_H
#define LED_PROC_H
#include "stm32f1xx.h"

void led_init(void); 
void LED_blink (void);
void LED_blink_on_off (uint8_t button_state);

#endif