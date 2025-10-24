#include "uart_proc.h"
#include "uart_periph.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

char message_blink_LED_ON [] = "LED BLINKING ON \n";				
char message_blink_LED_OFF [] = "LED BLINKING OFF \n";				

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void uart_send_str (char* str)							//функция передачи строки по UART
{	
    while (*str)								// Цикл по символам строки (до \0)
    {
      waiting_for_TX_UART_end ();				        
      writing_char_to_DR (*str);						
      str++;								        //увеличиваем указатель
    }	
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void uart_send (uint8_t button_state)
{
   static uint8_t previous_button_state = 0;
   
   if (previous_button_state != button_state)
   {
      switch (button_state)
      {
        case 0:
              uart_send_str (message_blink_LED_OFF);			
              break;
        case 1:
              uart_send_str (message_blink_LED_ON);			
              break;	
      }
   }
  
    previous_button_state = button_state;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
