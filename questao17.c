/**  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "Utility.h"

#define LED1_ON GPIOA->ODR |= (1)// Desliga o PA0
#define LED1_OFF GPIOA->ODR &= ~(1) // Liga o PA0


int main(void)
{
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;

	GPIOA->MODER |= (0b01);

    while(1)
    {
    	for (int i = 600; i <= 2400; i+=10){
    		LED1_ON;
    		Delay_us(i);
    		LED1_OFF;
    		Delay_us(20000 - i);
    	}

    	for (int i = 2400; i >= 600; i-=10){
			LED1_ON;
			Delay_us(i);
			LED1_OFF;
			Delay_us(20000 - i);
		}
    }
}
