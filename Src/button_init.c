#include "button_init.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void PORTA_init (void)							        //Функция инициализации порта PORTA PIN0
{	
    SET_BIT (RCC->APB2ENR, RCC_APB2ENR_IOPAEN);			                //включение тактироания порта port A
		
    CLEAR_BIT (GPIOA->CRL, GPIO_CRL_MODE0_0);			                //MODE0 установка 00 - 	Input mode
    CLEAR_BIT (GPIOA->CRL, GPIO_CRL_MODE0_1);			                //MODE0 set 00 - Input mode
	
    CLEAR_BIT (GPIOA->CRL, GPIO_CRL_CNF0_0);			                //CNF0 set 10 - Input with pull-up / pull-down
    SET_BIT (GPIOA -> CRL, GPIO_CRL_CNF0_1);			                //CNF0 set 10 - Input with pull-up / pull-down
		
    SET_BIT (GPIOA -> ODR, GPIO_ODR_ODR0);				        //включение подтяжки Input pull-up
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void TIM2_init (void)								//функция инициализации TIM2
{	
    SET_BIT (RCC->APB1ENR, RCC_APB1ENR_TIM2EN);				        //включение тактирования TIM2
	
    WRITE_REG (TIM2 -> PSC, 799);						//yстановка предделителя. 8МГц/(799+1)=10 000 тиков за секунду
    WRITE_REG (TIM2 -> ARR, 100);						//задержка 0.01с - частота 100Гц (10ms). (10 000*0.01=100)
	
    SET_BIT (TIM2 ->DIER,TIM_DIER_UIE);					        //ключения прерывания по событию обновления таймера TIM3
    NVIC_EnableIRQ (TIM2_IRQn);						        //включение прерывания для TIM3
	
    SET_BIT (TIM2->CR1,TIM_CR1_CEN);					        //включение таймера
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
