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

    const uint8_t mask[16]={ 0b00111111, //0
    		0b00000110, //1
			0b01011011, //2
			0b01001111, //3
			0b01100110, //4
			0b01101101, //5
			0b01111101, //6
			0b00000111, //7
			0b01111111, //8
			0b01101111, //9
			0b01110111, //A
			0b01111100, //B
			0b00111001, //C
			0b01011110, //D
			0b01111001, //E
			0b01110001}; //F

    while(1)
    {

    	for (int i = 0; i < 16; i++){
    		GPIOD->ODR = mask[i];
    		Delay_ms(500);
    	}

    	for (int i = 14; i >= 0; i--){
    	    	GPIOD->ODR = mask[i];
    	    	Delay_ms(500);
    	}

    }
}
