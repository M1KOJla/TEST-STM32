/*
  Board: BluePill
  MCU: STM32F103CB
  SYS_FREQ: 8MHz

При нажатии на кнопку происходит включение и выключение функции моргания
светодиода, отправка по UART в консоль сообщения с состоянием светодиода.
В программе обработки нажатия кнопки добавлен программный антидребезг кнопки.

*/




#include "led_proc.h"
#include "button_proc.h"
#include "uart_periph.h"
#include "uart_proc.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void main(void)
{
  
  uint8_t button_state=0;
    
  led_init();
  button_init();
  uart1_init ();	
  
  while (1)
  {
   button_state = track_button_press_again();
   LED_blink_on_off (button_state);
   uart_send (button_state);  
  }
 
}
