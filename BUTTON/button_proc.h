#ifndef BUTTON_PROC_H
#define BUTTON_PROC_H
#include "stm32f1xx.h"

void button_init(void);
void button_press_tracking (void);
uint8_t track_button_press_again (void);

#endif