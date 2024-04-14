#include "stm32f103c6_gpio_driver.h"

/****************************** APIs Functions Definitions**********************************/
uint8 Get_CRLH_Position(uint16 PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN0:
		return 0;
		break;
	case GPIO_PIN1:
		return 4;
		break;
	case GPIO_PIN2:
		return 8;
		break;
	case GPIO_PIN3:
		return 12;
		break;
	case GPIO_PIN4:
		return 16;
		break;
	case GPIO_PIN5:
		return 20;
		break;
	case GPIO_PIN6:
		return 24;
		break;
	case GPIO_PIN7:
		return 28;
		break;
	case GPIO_PIN8:
		return 0;
		break;
	case GPIO_PIN9:
		return 4;
		break;
	case GPIO_PIN10:
		return 8;
		break;
	case GPIO_PIN11:
		return 12;
		break;
	case GPIO_PIN12:
		return 16;
		break;
	case GPIO_PIN13:
		return 20;
		break;
	case GPIO_PIN14:
		return 24;
		break;
	case GPIO_PIN15:
		return 28;
		break;

	}
}
/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initialize GPIOx PINy according to the specified  parameters in PinConfig
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinConfig pointer to a Dt_GPIO_PinConfig that contains all informations required for pin
 * 					configurations
 * @retval			-None
 * Note- stm32f103c6 mcu has GPIO A,B,C,D,E circuits but LQFP48 package has only A,B,PART OF C,D exported as external PINS from
 * the mcu
 */

void MCAL_GPIO_Init(Dt_GPIO* GPIOx, Dt_GPIO_PinConfig* PinConfig)
{
	//Port configuration register LOW (GPIOx_CRL), configures pin from 0 to 7
	//Port configuration register HIGH (GPIOx_CRH), configures pin from 8 to 15
	volatile uint32 * configregister =NULL;
	uint8 PIN_Config = 0;
	if(PinConfig->GPIO_Pin_Number < GPIO_PIN8)
	{
		configregister = &GPIOx->CRL;
	}
	else
	{
		configregister = &GPIOx->CRH;
	}

	//Clear MODE and CNF 4 BITS
	(*configregister)&=~(0xF<<Get_CRLH_Position(PinConfig->GPIO_Pin_Number));

	//check if it is output pin
	if(		(PinConfig->GPIO_Pin_Mode ==GPIO_MODE_OUTPUT_AF_OD )||
			(PinConfig->GPIO_Pin_Mode ==GPIO_MODE_OUTPUT_AF_PP )||
			(PinConfig->GPIO_Pin_Mode ==GPIO_MODE_OUTPUT_OD )||
			(PinConfig->GPIO_Pin_Mode ==GPIO_MODE_OUTPUT_PP ))
	{
		//set CNF MODE 4 BITS
		PIN_Config = (((PinConfig->GPIO_Pin_Mode -4 ) <<2 ) | (PinConfig->GPIO_Output_Speed))&0x0F;
	}
	//input pin
	else //MODE 00 RESET STATE
	{
		if(PinConfig->GPIO_Pin_Mode == GPIO_MODE_INPUT_FLO ||PinConfig->GPIO_Pin_Mode == GPIO_MODE_ANALOG)
		{
			//set CNF 2 BITS
			PIN_Config = (((PinConfig->GPIO_Pin_Mode) <<2 ))&0x0F;

		}
		else if(PinConfig->GPIO_Pin_Mode == GPIO_MODE_INPUT_AF)//Consider it as input floating (as it is recommended configurations from the TRM)
		{
			//set CNF 2 BITS
			PIN_Config = (((GPIO_MODE_INPUT_FLO) <<2 ))&0x0F;
		}
		else //PU OR PD INPUT
		{
			PIN_Config = (((GPIO_MODE_INPUT_PU) <<2 ))&0x0F; //pu and pd both has 0x02 at MODE
			if (PinConfig->GPIO_Pin_Mode ==GPIO_MODE_INPUT_PU)
			{
				//PxODR to differ between them - table 20 in TRM
				//1 for PU
				GPIOx->ODR|=PinConfig->GPIO_Pin_Number;
			}
			else
			{
				//PxODR to differ between them - table 20 in TRM
				//0 for PD
				GPIOx->ODR&=~(PinConfig->GPIO_Pin_Number);
			}
		}
	}
	//Write to CRL or CRH
	(*configregister)|=(PIN_Config<<Get_CRLH_Position(PinConfig->GPIO_Pin_Number));

}

/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset all GPIO Registers
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval			-None
 */
void MCAL_GPIO_DeInit(Dt_GPIO* GPIOx)
{
	/*	//reset values for all registers
	GPIOx->BRR 	= 	0x00000000;
	GPIOx->BSRR = 	0x00000000;
	GPIOx->CRH 	= 	0x44444444;
	GPIOx->CRL 	= 	0x44444444;
	//IDR  (READ ONLY)
	GPIOx->LCKR = 	0x00000000;
	GPIOx->ODR = 	0x00000000;*/

	//or use the reset controller peripheral
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR|=(1<<2); // BIT 2 IOPARST: IO PORTA RESET
		RCC->APB2RSTR&=~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR|=(1<<3); // BIT 3 IOPARST: IO PORTB RESET
		RCC->APB2RSTR&=~(1<<3);
	}
	if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR|=(1<<4); // BIT 4 IOPARST: IO PORTC RESET
		RCC->APB2RSTR&=~(1<<4);
	}
	if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR|=(1<<5);// BIT 5 IOPARST: IO PORTD RESET
		RCC->APB2RSTR&=~(1<<5);
	}
	if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR|=(1<<6);// BIT 6 IOPARST: IO PORTE RESET
		RCC->APB2RSTR&=~(1<<6);
	}

}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read specific pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-Input Pin Value (two value based on @ref GPIO_PIN_STATE)
 */
uint8 MCAL_GPIO_ReadPin(Dt_GPIO* GPIOx,uint16 PinNumber)
{
	uint8 pin_value;
	if(((GPIOx->IDR)&PinNumber) != (uint32)GPIO_PIN_LOW)
	{
		pin_value = GPIO_PIN_HIGH;
	}
	else
	{
		pin_value = GPIO_PIN_LOW;
	}
	return pin_value;
}
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read port value
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval			-Input Port Value
 */
uint16 MCAL_GPIO_ReadPort(Dt_GPIO* GPIOx)
{
	uint16 port_value = GPIOx->IDR;
	return port_value;
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-write on specific output pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @param [in] 		-value , The value to be written to the pin(two value based on @ref GPIO_PIN_STATE)
 * @retval			-None
 */
void MCAL_GPIO_WritePin(Dt_GPIO* GPIOx,uint16 PinNumber,uint8 value)
{

	if(value == (uint8)GPIO_PIN_HIGH)
	{
		//Port bit set/reset register (GPIOx_BSRR)
		//Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32)PinNumber;// This is would be more efficient than accessing ODR register to read and to write
	}
	else
	{
		//Port bit reset register (GPIOx_BRR)
		//Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR=(uint32)PinNumber;  // This is would be more efficient than accessing ODR register to read and to write
	}
}
/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-write on specific output port
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-value , The value to be written to port
 * @retval			-None
 */
void MCAL_GPIO_WritePort(Dt_GPIO* GPIOx,uint16 value)
{
	GPIOx->ODR =  (uint32)value;
}
/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-toggle specific pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-None
 */
void MCAL_GPIO_TogglePin(Dt_GPIO* GPIOx,uint16 PinNumber)
{
	GPIOx->ODR^=PinNumber; //PinNumber is (1<<pin_no)
}
/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-the locking mechanism allows the IO configurations to be forzen
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-Ok if pin config is locked or ERROR if pin not locked @ref GPIO_LOCK_STATUS
 */
uint8 MCAL_GPIO_LockPin(Dt_GPIO* GPIOx,uint16 PinNumber)
{
		/*
	Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.
	 */
	//set LCK 16
	volatile uint32 temp = 1<<16;
	//set LCKy
	temp|=PinNumber;
	//Write 1
	GPIOx->LCKR= temp;
	//Write 0
	GPIOx->LCKR= PinNumber;
	//Write 1
	GPIOx->LCKR= temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1
	if(GPIOx->LCKR & (1<<16) )
	{
		return GPIO_LOCK_OK;
	}
	else
	{
		return GPIO_LOCK_ERROR;
	}


}
