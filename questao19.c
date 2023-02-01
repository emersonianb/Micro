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
	GPIOA->OTYPER |= (1);

    while(1)
    {
      LED1_ON;
      Delay_ms(100);
      LED1_OFF;
      Delay_ms(100);

  }
}
