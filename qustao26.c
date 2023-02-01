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

#define K1 !(GPIOE->IDR & (1<<3)) //TESTA SE ESTA PRESSIONADO
#define K0 !(GPIOE->IDR & (1<<4)) //TESTA SE ESTA PRESSIONADO

#define LED1_ON GPIOA->ODR |= (1)// Desliga o PA0
#define LED1_OFF GPIOA->ODR &= ~(1) // Liga o PA0


int main(void)
{
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1<<4;

	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	GPIOA->MODER |= (0b01);

	int ternibou;
	int comecou = 600;
    while(1)
    {

		for (int i = comecou; i <= 2400; i+=10){
			if (K0){
				LED1_ON;
				Delay_us(i);
				LED1_OFF;
				Delay_us(20000 - i);
				ternibou = i;
			}
		}
		for (int i = ternibou; i >= 600; i-=10){
			if (K1){
				LED1_ON;
				Delay_us(i);
				LED1_OFF;
				Delay_us(20000 - i);
				comecou = i;
			}
		}
    }
}
