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

#define K1 !(GPIOE->IDR & (1<<3)) //TESTA SE ESTA PRESSIONADO
#define K0 !(GPIOE->IDR & (1<<4)) //TESTA SE ESTA PRESSIONADO

#define LED1_ON GPIOA->ODR &= ~(1<<6) //LIGA O PINO PA6
#define LED1_OFF GPIOA->ODR |= (1<<6) //DESLIGA O PINO PA6

#define LED2_ON GPIOA->ODR &= ~(1<<7) // LIGA O PINO PA7
#define LED2_OFF GPIOA->ODR |= (1<<7) // DESLIGA O PINO PA7

int main(void)
{
    RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
    RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

    //configurando PA6 como saída (o pino PA6 tem um LED conectado)
    GPIOA->MODER |= (0b01 << 12);
    //configurando PA7 como saída (o pino PA6 tem um LED conectado)
    GPIOA->MODER |= (0b01 << 14);

    //Configurando o pino PE3 como entrada
    GPIOE->MODER &= ~(0b11 << 6);
    GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
    //Configurando o pino PE4 como entrada
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto


   LED1_OFF;
   LED2_OFF;
    while(1)
    {
        if(K0)
        {
        	LED1_ON;
        }
        else
        {
        	LED1_OFF;
        }
        if(K1)
        {
        	LED2_ON;
        }
        else
        {
           LED2_OFF;
        }
    }
}
