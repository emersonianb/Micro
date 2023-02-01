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

			

#define LED1_ON GPIOA->ODR |= (1)// Desliga o PA6
#define LED1_OFF GPIOA->ODR &= ~(1) // Liga o PA6

#define LED2_OFF GPIOA->ODR &= ~(1 << 1) // Liga o PA6
#define LED2_ON GPIOA->ODR |= (1 << 1)// Desliga o PA6


int main(void)
{
	Configure_Clock();
	Delay_Start();

    RCC->AHB1ENR |= 1 << 3;//habilita o clock do GPIOD
    RCC->AHB1ENR |= 1;

    GPIOD->MODER |= (0b01);
    GPIOD->MODER |= (0b01 << 2);
    GPIOD->MODER |= (0b01 << 4);
    GPIOD->MODER |= (0b01 << 6);
    GPIOD->MODER |= (0b01 << 8);
    GPIOD->MODER |= (0b01 << 10);
    GPIOD->MODER |= (0b01 << 12);

    GPIOA->MODER |= (0b01);
	GPIOA->MODER |= (0b01 << 2);


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


    int cont = 0;



    while(1)
    {

    	for(int j = 0; j < 16; j++){
    		for (int i = 0; i < 16; i++){
				for (int c = 0; c < 5; c++){
					LED2_ON;
					  LED1_OFF;
					  GPIOD->ODR = mask[j];
					  Delay_ms(5);

					  LED1_ON;
					  LED2_OFF;
					  GPIOD->ODR = mask[i];
					  Delay_ms(5);
				}
			}
    	}


    	for(int j = 14; j >= 0; j--){
    		for (int i = 15; i >= 0; i--){
				for (int c = 0; c < 5; c++){
					LED2_ON;
					  LED1_OFF;
					  GPIOD->ODR = mask[j];
					  Delay_ms(5);

					  LED1_ON;
					  LED2_OFF;
					  GPIOD->ODR = mask[i];
					  Delay_ms(5);
				}
			}
    	}
    }
}
