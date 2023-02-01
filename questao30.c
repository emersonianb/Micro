void questao30geo(){

	void led_on(int i){
		if (i == 0){
			LED1_ON;
			Delay_ms(200);
			LED1_OFF;
			Delay_ms(200);
		}
		else if (i == 1){
			LED2_ON;
			Delay_ms(200);
			LED2_OFF;
			Delay_ms(200);
		} else if (i == 2){
			LED3_ON;
			Delay_ms(200);
			LED3_OFF;
			Delay_ms(200);
		}
	}


	int list[3];

	for(int i = 0; i < 3; i++){
		list[i] = rand() %2;
		if (list[i] == 1){
			led_on(i);
		}
	}

	for(int i = 0; i < 3; i ++){
		while(!K0 && !K1 && !K2){
			if (list[i] == 0){
				Delay_ms(1000);
				i += 1;
				if (i == 3){
					break;
				}
			}
		}
		while(K0 || K1 || K2){
			if ((K0 && i == 0) || (K1 && i == 1) || (K2 && i == 2)){
				if (list[i] == 1){
					led_on(i);
					break;
				}else{
					LED_ERROR;
					i = 0;
				}
			} else {
				LED_ERROR;
				i = 0;
			}
		}
	} LED_OK;
}