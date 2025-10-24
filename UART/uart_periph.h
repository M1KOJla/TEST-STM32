#ifndef UART_PERIPH_H
#define UART_PERIPH_H

#include "stm32f1xx.h"
#define SYSCLK_FREQ  8000000U							//макрос системной частоты МК

void uart1_init (void);	
void waiting_for_TX_UART_end (void);
void writing_char_to_DR (char c);

#endif 