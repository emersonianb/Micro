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

#define K2 (GPIOA->IDR & (1 << 0)) //TESTA SE ESTA PRESSIONADO
#define K1 !(GPIOE->IDR & (1<<3)) //TESTA SE ESTA PRESSIONADO
#define K0 !(GPIOE->IDR & (1<<4)) //TESTA SE ESTA PRESSIONADO


int main(void)
{
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

	//Configurando o pino PE3 como entrada
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
	//Configurando o pino PE4 como entrada
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto

	GPIOA->MODER &= ~(0b11);
	GPIOA->PUPDR |= (0b10);

    RCC->AHB1ENR |= 1 << 3;//habilita o clock do GPIOD
    RCC->AHB1ENR |= 1;

    GPIOD->MODER |= (0b01);
    GPIOD->MODER |= (0b01 << 2);
    GPIOD->MODER |= (0b01 << 4);
    GPIOD->MODER |= (0b01 << 6);
    GPIOD->MODER |= (0b01 << 8);
    GPIOD->MODER |= (0b01 << 10);
    GPIOD->MODER |= (0b01 << 12);


	const uint8_t mask[16]={
			0b00000110, //1
			0b01011011, //2
			0b01001111};//3

    while(1)
    {
    	if (K2){
    		GPIOD->ODR = mask[0];
    	}
    	else if (K0){
    		GPIOD->ODR = mask[1];
    	}
    	else if (K1){
    		GPIOD->ODR = mask[2];
    	}


    }
}
