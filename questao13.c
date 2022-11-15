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
			

#define LED1_ON GPIOD->ODR |= (1)// Desliga o PA6
#define LED1_OFF GPIOD->ODR &= ~(1) // Liga o PA6

#define LED2_OFF GPIOD->ODR &= ~(1 << 1) // Liga o PA6
#define LED2_ON GPIOD->ODR |= (1 << 1)// Desliga o PA6

#define LED3_OFF GPIOD->ODR &= ~(1 << 2) // Liga o PA6
#define LED3_ON GPIOD->ODR |= (1 << 2)// Desliga o PA6

#define LED4_OFF GPIOD->ODR &= ~(1 << 3) // Liga o PA6
#define LED4_ON GPIOD->ODR |= (1 << 3)// Desliga o PA6

#define LED5_OFF GPIOD->ODR &= ~(1 << 4) // Liga o PA6
#define LED5_ON GPIOD->ODR |= (1 << 4)// Desliga o PA6

#define LED6_OFF GPIOD->ODR &= ~(1 << 5) // Liga o PA6
#define LED6_ON GPIOD->ODR |= (1 << 5)// Desliga o PA6

#define LED7_OFF GPIOD->ODR &= ~(1 << 6) // Liga o PA6
#define LED7_ON GPIOD->ODR |= (1 << 6)// Desliga o PA6


int main(void)
{
	Configure_Clock();
	Delay_Start();

    RCC->AHB1ENR |= 1 << 3;         //habilita o clock do GPIOD

    GPIOD->MODER |= (0b01);
    GPIOD->MODER |= (0b01 << 2);
    GPIOD->MODER |= (0b01 << 4);
    GPIOD->MODER |= (0b01 << 6);
    GPIOD->MODER |= (0b01 << 8);
    GPIOD->MODER |= (0b01 << 10);
    GPIOD->MODER |= (0b01 << 12);

    while(1)
    {
    	GPIOD->ODR = 126;
    	Delay_ms(1000);

    	GPIOD->ODR = 48;
		Delay_ms(1000);

		GPIOD->ODR = 109;
		Delay_ms(1000);

		GPIOD->ODR = 121;
		Delay_ms(1000);

		GPIOD->ODR = 51;
		Delay_ms(1000);

		GPIOD->ODR = 91;
		Delay_ms(1000);

		GPIOD->ODR = 95;
		Delay_ms(1000);

		GPIOD->ODR = 112;
		Delay_ms(1000);

		GPIOD->ODR = 127;
		Delay_ms(1000);

		GPIOD->ODR = 123;
		Delay_ms(1000);

		GPIOD->ODR = 119;
		Delay_ms(1000);

		GPIOD->ODR = 31;
		Delay_ms(1000);

		GPIOD->ODR = 78;
		Delay_ms(1000);

		GPIOD->ODR = 61;
		Delay_ms(1000);

		GPIOD->ODR = 79;
		Delay_ms(1000);

		GPIOD->ODR = 71;
		Delay_ms(1000);
    }
}
