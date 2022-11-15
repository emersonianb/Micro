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
			

#define LED1_ON GPIOA->ODR &= ~(1 <<6) // Liga o PA6
#define LED1_OFF GPIOA->ODR |= (1 << 6)// Desliga o PA6

#define LED2_ON GPIOA->ODR &= ~(1 << 7)
#define LED2_OFF GPIOA->ODR |= (1 << 7)

int main(void)
{
	Configure_Clock();
	Delay_Start();

    RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA

    GPIOA->MODER |= (0b01 << 12); // Configurando PA6 como saída
    GPIOA->MODER |= (0b01 << 14);

    while(1)
    {
    	for (int i = 0; i < 4; i++){
    		if (i%2==0){
    			LED1_OFF;
    			if (i>1){
    				LED2_ON;
    			} else{
    				LED2_OFF;
    			}
    			Delay_ms(1000);
    		} else{
    			LED1_ON;
				if (i>1){
					LED2_ON;
				} else{
					LED2_OFF;
				}
				Delay_ms(1000);
    		}

    	}
    }
}
