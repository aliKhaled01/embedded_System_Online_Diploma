#include "driver.h"
#include <stdint.h>
#include <stdio.h>
void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(unsigned char* is_updated)
{	
	unsigned char curr_value = GPIOA_IDR & 0xFF;
	static unsigned char prev_value = 0;
	if(prev_value != curr_value)
	{
	*is_updated = 1;
	}
	else
	{
		*is_updated = 0;
	}
	prev_value = GPIOA_IDR & 0xFF;
	return curr_value;

}

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	SET_BIT(GPIOA_ODR,13);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
