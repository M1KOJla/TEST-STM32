#ifndef UART_PROC_H
#define UART_PROC_H
#include "stm32f1xx.h"

void uart_send_str (char* str);
void uart_send (uint8_t button_state);
void uart_repit (void);


#endif