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
			
#define LED1_ON GPIOA->ODR &= ~(1 <<6)
#define LED1_OFF GPIOA->ODR |= (1 << 6)

int main(void)
{
    Configure_Clock(); //configura o sistema clock do micro
    Delay_Start(); //inicializa as funções de delay

    RCC->AHB1ENR |= 1;

    GPIOA->MODER |= (0b01 << 12);

    int cont = 0;
    int x;

    while (1){

    	if (cont < 10){
    		cont += 1;
    	} else{
    		cont = 1;
    	}

    	x = 50/cont;

    	for (int i=0; i<cont; i++){
    		LED1_ON;
			Delay_ms(x);
			LED1_OFF;
			Delay_ms((1000/cont)-x);
    	}

    }
}
