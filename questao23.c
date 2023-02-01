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

#define K0 !(GPIOE->IDR & (1<<4)) //TESTA SE ESTA PRESSIONADO

#define LED1_ON GPIOA->ODR &= ~(1<<6) //LIGA O PINO PA6
#define LED1_OFF GPIOA->ODR |= (1<<6) //DESLIGA O PINO PA6

int main(void)
{
    RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
    RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

    //configurando PA6 como saída (o pino PA6 tem um LED conectado)
    GPIOA->MODER |= (0b01 << 12);

    //Configurando o pino PE3 como entrada
    GPIOE->MODER &= ~(0b11 << 6);
    GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
    //Configurando o pino PE4 como entrada
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
  int ligado = 0;
  LED1_OFF;

  	Configure_Clock();
  	Delay_Start();

    while(1)
    {
        if(K0)
        {
          if (ligado){
            LED1_OFF;
			Delay_ms(250);
            ligado = 0;

          }
          else{
            LED1_ON;
			Delay_ms(250);
            ligado = 1;
          }
        }
    }
    // GPIOA->OTYPER |= (1<<0);
}
