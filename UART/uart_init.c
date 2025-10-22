#include "uart_init.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void uart1_init (void)								//функция инициализации UART1
{
    SET_BIT (RCC->APB2ENR, RCC_APB2ENR_IOPAEN);				        //включение тактирования PORTA
    SET_BIT (RCC->APB2ENR, RCC_APB2ENR_AFIOEN);				        //включение тактирования альтернативной функции PORTA
	
										// Настройка TX - PORTA9
    CLEAR_BIT (GPIOA->CRH, GPIO_CRH_CNF9);					//сброс CNF9
    SET_BIT (GPIOA->CRH, GPIO_CRH_CNF9_1);					//10: Alternate function output Push-pull
    SET_BIT (GPIOA->CRH, GPIO_CRH_MODE9_0);					//01: Output mode, max speed 10 MHz
		
										// Настройка RX - PORTA10
    CLEAR_BIT (GPIOA->CRH, GPIO_CRH_MODE10);				        //MODE10 установка 00 - 	Input mode
    CLEAR_BIT (GPIOA->CRH, GPIO_CRH_CNF10_0);				        //CNF0 set 10 - Input with pull-up / pull-down
    SET_BIT (GPIOA -> CRH, GPIO_CRH_CNF10_1);				        //CNF0 set 10 - Input with pull-up / pull-down	
    SET_BIT (GPIOA -> ODR, GPIO_ODR_ODR10);					//включение подтяжки Input pull-up

    SET_BIT (RCC->APB2ENR, RCC_APB2ENR_USART1EN);				//включение тактирования UART1  
    SET_BIT (USART1->BRR, 0x341);                                               //установка делителя частоты для скорости 9600Kbps
										//8 000 000/16*9600=52.0833
										//0d52=0x34
										//0d0.0833*16=0d1 или 0x1
										//BRR=0x341
	
    SET_BIT (USART1->CR1, USART_CR1_TE);					//включение передатчика UART1
    SET_BIT (USART1->CR1, USART_CR1_RE);					//включение приемника UART1
    SET_BIT (USART1->CR1, USART_CR1_UE);					//включение UART1		
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void waiting_for_TX_UART_end (void)
{
    while (!(USART1 -> SR & USART_SR_TC))                                       //ждем пока завершиться передача по UART
    {
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void writing_char_to_DR (char c)
{
    USART1 -> DR = c;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------