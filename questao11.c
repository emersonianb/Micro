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

#define LED8_OFF GPIOD->ODR &= ~(1 << 7) // Liga o PA6
#define LED8_ON GPIOD->ODR |= (1 << 7)// Desliga o PA6

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
    GPIOD->MODER |= (0b01 << 14);


    while(1)
    {
    	for(int i = 0; i < 256; i++){
    		GPIOD->ODR = i;
    		Delay_ms(500);
    	}
    }
}
