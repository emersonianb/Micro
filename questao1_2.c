/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"	//bibliotecas padrão STM32F4
#include "stdio.h"
#include "Utility.h"	//biblioteca de funções utilitárias


//função principal
int main(void)
{
	Configure_Clock();	//configura o sistema de clock
	Delay_Start();		//inicializa funções de Delay

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 8;				//inicialização do pino PA4 no modo analógico

	RCC->APB1ENR |= RCC_APB1ENR_DACEN;	//habilita o clock da interface digital do DAC
	DAC->CR |= DAC_CR_EN1;				//habilita o canal 1 do DAC
	DAC->CR |= DAC_CR_BOFF1;	//desabilita o buffer analógico do DAC1

	while(1)
	{
		for(int i=0; i<4096; i++)
		{
			DAC->DHR12R1 = i;	//escreve no DAC1
			Delay_ms(1);					//aguarda a próxima amostra
		}
		for(int i=4095; i>=0; i--)
		{
			DAC->DHR12R1 = i;	//escreve no DAC1
			Delay_ms(1);					//aguarda a próxima amostra
		}
	}

}
