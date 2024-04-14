/********************************* INCLUDES****************************************************/
#include "stm32f103c6_exti_driver.h"
#include "stm32f103c6_gpio_driver.h"

/******************************GENERIC VARIABLES********************************************/

void (*GP_irq_callback[16])(void); //array of 16 elements each is pointer to function with void arguments , returns void

/******************************GENERIC FUNCTIONS********************************************/
void Enable_NVIC_Irq(uint16 line_no)
{
	switch(line_no)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE();
		break;
	}
}
void Disable_NVIC_Irq(uint16 line_no)
{
	switch(line_no)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE();
		break;
	}
}
void configure_exti(Dt_exti_config* exti_config)
{
	//1- configure GPIO to be AF input , floating
	Dt_GPIO_PinConfig pincfg;
	pincfg.GPIO_Pin_Number = exti_config->exti_mapping.gpio_pin_no;
	pincfg.GPIO_Pin_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(exti_config->exti_mapping.gpio_port,&pincfg);

	//2- configure AFIO to route EXTI with the required pin
	uint8 AFIO_EXTICR_index 			= (exti_config->exti_mapping.exti_input_line_no / 4);
	uint8 AFIO_EXTICR_bits_start_pos 	= (exti_config->exti_mapping.exti_input_line_no %4 )*4;
	//clear 4 bits EXTIx[3:0]
	AFIO->EXTICR[AFIO_EXTICR_index]&=~(0xF<<AFIO_EXTICR_bits_start_pos);
	AFIO->EXTICR[AFIO_EXTICR_index]|=((GET_CORRESPONDING_EXTI_VALUE(exti_config->exti_mapping.gpio_port)&0xF)<<AFIO_EXTICR_bits_start_pos);

	//3- configure EXTI controller rising /falling detection
	EXTI->RTSR &=~(0x1<<exti_config->exti_mapping.exti_input_line_no);
	EXTI->FTSR &=~(0x1<<exti_config->exti_mapping.exti_input_line_no);
	if(exti_config->trigger_condition ==EXTI_TRIGGER_RISING)
	{
		EXTI->RTSR |=(0x1<<exti_config->exti_mapping.exti_input_line_no);
	}
	else if(exti_config->trigger_condition ==EXTI_TRIGGER_FALLING)
	{
		EXTI->FTSR |=(0x1<<exti_config->exti_mapping.exti_input_line_no);
	}
	else if(exti_config->trigger_condition ==EXTI_TRIGGER_FALLING_RISING)
	{
		EXTI->RTSR |=(0x1<<exti_config->exti_mapping.exti_input_line_no);
		EXTI->FTSR |=(0x1<<exti_config->exti_mapping.exti_input_line_no);
	}

	//4- update irq handling callback
	GP_irq_callback[exti_config->exti_mapping.exti_input_line_no] =exti_config->p_irq_callback;

	//5- enable / disable irq  EXTI & NVIC
	if(exti_config->irq_enable==EXTI_IRQ_ENABLE)
	{
		//write 1 to corresponding interrupt mask register bit
		EXTI->IMR |=(1<<exti_config->exti_mapping.exti_input_line_no);

		Enable_NVIC_Irq(exti_config->exti_mapping.exti_input_line_no);
	}
	else if(exti_config->irq_enable==EXTI_IRQ_DISABLE)
	{
		//write 0to corresponding interrupt mask register bit
		EXTI->IMR &=~(1<<exti_config->exti_mapping.exti_input_line_no);

		Disable_NVIC_Irq(exti_config->exti_mapping.exti_input_line_no);
	}
}

/******************************APIs Functions Definitions**********************************/

/**================================================================
 * @Fn				-MCAL_exti_gpio_deinit
 * @brief 			-reset EXTI Registers and NVIC corresponding IRQ mask
 * @retval			-None
 */
void MCAL_exti_gpio_deinit(void)
{
	EXTI->IMR 	=	 0x00000000;
	EXTI->EMR 	= 	 0x00000000;
	EXTI->RTSR 	= 	 0x00000000;
	EXTI->FTSR 	=	 0x00000000;
	EXTI->SWIER = 	 0x00000000;
	/*
 PRx: Pending bit
0: No trigger request occurred
1: selected trigger request occurred
This bit is set when the selected edge event arrives on the external interrupt line. This bit is
cleared by writing a ‘1’ into the bit.
	 */
	EXTI->PR 	= 	 0xFFFFFFFF;
	//disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_DISABLE();
	NVIC_IRQ7_EXTI1_DISABLE();
	NVIC_IRQ8_EXTI2_DISABLE();
	NVIC_IRQ9_EXTI3_DISABLE();
	NVIC_IRQ10_EXTI4_DISABLE();
	NVIC_IRQ23_EXTI5_9_DISABLE();
	NVIC_IRQ40_EXTI10_15_DISABLE();
}

/**================================================================
 * @Fn				-MCAL_exti_gpio_init
 * @brief 			-Initialize EXTI at specific pin and specify mask(EN/DIS) , trigger condition for the irq  and irq callback function
 * @param [in]	 	-exti_config set by @ref EXTI_define , @ref EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			-None
 */
void MCAL_exti_gpio_init(Dt_exti_config* exti_config)
{
	configure_exti(exti_config);
}
/**================================================================
 * @Fn				-MCAL_exti_gpio_update
 * @brief 			-Update at run time EXTI at specific pin and specify mask(EN/DIS) , trigger condition for the irq  and irq callback function
 * @param [in]	 	-exti_config set by @ref EXTI_define , @ref EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			-None
 */
void MCAL_exti_gpio_update(Dt_exti_config* exti_config)
{
	configure_exti(exti_config);
}

/******************************************ISR FUNCTIONS******************************************/
void EXTI0_IRQHandler(void)
{
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	//clear to avoid infinite interrupt handling
	EXTI->PR |=(1<<0);
	//call corresponding callback
	GP_irq_callback[0]();
}
void EXTI1_IRQHandler(void)
{
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	//clear to avoid infinite interrupt handling
	EXTI->PR |=(1<<1);
	//call corresponding callback
	GP_irq_callback[1]();
}
void EXTI2_IRQHandler(void)
{
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	//clear to avoid infinite interrupt handling
	EXTI->PR |=(1<<2);
	//call corresponding callback
	GP_irq_callback[2]();
}
void EXTI3_IRQHandler(void)
{
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	//clear to avoid infinite interrupt handling
	EXTI->PR |=(1<<3);
	//call corresponding callback
	GP_irq_callback[3]();
}
void EXTI4_IRQHandler(void)
{
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	//clear to avoid infinite interrupt handling
	EXTI->PR |=(1<<4);
	//call corresponding callback
	GP_irq_callback[4]();
}
void EXTI9_5_IRQHandler(void)
{
if(EXTI->PR & 1<<5) {EXTI->PR|=(1<<5);GP_irq_callback[5]();}
if(EXTI->PR & 1<<6) {EXTI->PR|=(1<<6);GP_irq_callback[6]();}
if(EXTI->PR & 1<<7) {EXTI->PR|=(1<<7);GP_irq_callback[7]();}
if(EXTI->PR & 1<<8) {EXTI->PR|=(1<<8);GP_irq_callback[8]();}
if(EXTI->PR & 1<<9) {EXTI->PR|=(1<<9);GP_irq_callback[9]();}
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10) {EXTI->PR|=(1<<5);GP_irq_callback[10]();}
	if(EXTI->PR & 1<<11) {EXTI->PR|=(1<<6);GP_irq_callback[11]();}
	if(EXTI->PR & 1<<12) {EXTI->PR|=(1<<7);GP_irq_callback[12]();}
	if(EXTI->PR & 1<<13) {EXTI->PR|=(1<<8);GP_irq_callback[13]();}
	if(EXTI->PR & 1<<14) {EXTI->PR|=(1<<9);GP_irq_callback[14]();}
	if(EXTI->PR & 1<<15) {EXTI->PR|=(1<<9);GP_irq_callback[15]();}
}

