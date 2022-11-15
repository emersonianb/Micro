/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "Utility.h"
			
#define LED1_ON GPIOA->ODR &= ~(1 <<6)
#define LED1_OFF GPIOA->ODR |= (1 << 6)
#define BUZZER_ON GPIOC->ODR |= (0b01 << 11)
#define BUZZER_OFF GPIOC->ODR &= ~(0b01 << 11)

int main(void)
{
    Configure_Clock(); //configura o sistema clock do micro
    Delay_Start(); //inicializa as funções de delay

    RCC->AHB1ENR |= 1 << 2;

    GPIOC->MODER |= (0b01 << 22);

    while (1){

    	for (int i=0; i<4; i++){
    		BUZZER_ON;
			  Delay_ms(50);
	      BUZZER_OFF;
			  Delay_ms(200);
    	}

    	Delay_ms(500);
    }
}
