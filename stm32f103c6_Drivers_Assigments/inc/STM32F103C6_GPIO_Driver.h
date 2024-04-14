#ifndef STM32F103C6_GPIO_Driver_H
#define STM32F103C6_GPIO_Driver_H

/*********************************INCLUDES**************************************/
#include "STM32F103C6.h"



/*********************************CONFIG STRUCTURE**************************************/
typedef struct
{
	/*
	 * Specifies the GPIO pin number to be configured
	 * This Parameter MUST be to a value of @ref GPIO_PINS_no_define
	 */
	uint16 GPIO_Pin_Number;

	/*
	 * Specifies the GPIO pin mode to be configured
	 * This Parameter MUST be to a value of @ref GPIO_PINS_mode_define
	 */
	uint8 GPIO_Pin_Mode;

	/*
	 * Specifies the GPIO pin(output) speed to be configured
	 * This Parameter MUST be to a value of @ref GPIO_PINS_speed_define
	 */
	uint8 GPIO_Output_Speed;
}Dt_GPIO_PinConfig;

/*********************************Macros Configurations References***********************/
//@ref GPIO_PINS_no_define
#define GPIO_PIN0							((uint16)0x0001)
#define GPIO_PIN1							((uint16)0x0002)
#define GPIO_PIN2							((uint16)0x0004)
#define GPIO_PIN3							((uint16)0x0008)
#define GPIO_PIN4							((uint16)0x0010)
#define GPIO_PIN5							((uint16)0x0020)
#define GPIO_PIN6							((uint16)0x0040)
#define GPIO_PIN7							((uint16)0x0080)
#define GPIO_PIN8							((uint16)0x0100)
#define GPIO_PIN9							((uint16)0x0200)
#define GPIO_PIN10							((uint16)0x0400)
#define GPIO_PIN11							((uint16)0x0800)
#define GPIO_PIN12							((uint16)0x1000)
#define GPIO_PIN13							((uint16)0x2000)
#define GPIO_PIN14							((uint16)0x4000)
#define GPIO_PIN15							((uint16)0x8000)
#define GPIO_PIN_ALL						((uint16)0xFFFF)


#define GPIO_PIN_MASK						0x0000FFFFu


//@ref GPIO_PINS_mode_define
/*

0: Analog mode
1: Floating input
2: Input with pull-up
3: pull-down
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input
 */
#define GPIO_MODE_ANALOG							(0x00u)//Analog
#define GPIO_MODE_INPUT_FLO							(0x01u)//Floating input
#define GPIO_MODE_INPUT_PU							(0x02u)//input with pull-up
#define GPIO_MODE_INPUT_PD							(0x03u)//input with pull-down
#define GPIO_MODE_OUTPUT_PP							(0x04u)//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD							(0x05u)//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP						(0x06u)//Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD						(0x07u)//Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF							(0x08u)//Alternate function input

//@ref GPIO_PINS_speed_define
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz
 */
#define GPIO_SPEED_10M 	0x01u
#define GPIO_SPEED_2M 	0x02u
#define GPIO_SPEED_50M 	0x03u

//@ref GPIO_PIN_STATE
#define GPIO_PIN_HIGH 1
#define GPIO_PIN_LOW  0

//@ref GPIO_LOCK_STATUS
#define GPIO_LOCK_OK 	1
#define GPIO_LOCK_ERROR 0
/*********************************APIs Supported by "MCAL GPIO DRIVER"***********************/

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
void MCAL_GPIO_Init(Dt_GPIO* GPIOx, Dt_GPIO_PinConfig* PinConfig);
/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset all GPIO Registers
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval			-None
 */
void MCAL_GPIO_DeInit(Dt_GPIO* GPIOx);
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read specific pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-Input Pin Value (two value based on @ref GPIO_PIN_STATE)
 */
uint8 MCAL_GPIO_ReadPin(Dt_GPIO* GPIOx,uint16 PinNumber);
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read port value
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval			-Input Port Value
 */
uint16 MCAL_GPIO_ReadPort(Dt_GPIO* GPIOx);
/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-write on specific output pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @param [in] 		-value , The value to be written to the pin(two value based on @ref GPIO_PIN_STATE)
 * @retval			-None
 */
void MCAL_GPIO_WritePin(Dt_GPIO* GPIOx,uint16 PinNumber,uint8 value);
/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-write on specific output port
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-value , The value to be written to port
 * @retval			-None
 */
void MCAL_GPIO_WritePort(Dt_GPIO* GPIOx,uint16 value);
/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-toggle specific pin
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-None
 */
void MCAL_GPIO_TogglePin(Dt_GPIO* GPIOx,uint16 PinNumber);
/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-the locking mechanism allows the IO configurations to be forzen
 * @param [in]	 	-GPIOx, where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		-PinNumber , Please Set this parameter according to @ref GPIO_PINS_no_define
 * @retval			-None
 */
uint8 MCAL_GPIO_LockPin(Dt_GPIO* GPIOx,uint16 PinNumber);
#endif
