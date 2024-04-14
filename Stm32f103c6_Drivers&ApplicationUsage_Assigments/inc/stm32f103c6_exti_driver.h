#ifndef STM32F103C6_EXTI_Driver_H
#define STM32F103C6_EXTI_Driver_H
/*********************************INCLUDES**************************************/
#include "stm32f103c6_gpio_driver.h"

/*********************************CONFIG STRUCTURE**************************************/
typedef struct
{
uint16 exti_input_line_no;
Dt_GPIO* gpio_port;
uint16 gpio_pin_no;
uint8 ivt_irq_no;
}Dt_exti_gpio_mapping;

typedef struct
{

	Dt_exti_gpio_mapping exti_mapping; 			//specifies the external interrupt gpio mapping.
									   	   	   	//This parameter MUST be set based on @ref EXTI_define




	uint8 trigger_condition;					//specifies rising or falling or both to trigger pin exti
												//This parameter MUST be set based on @ref EXTI_Trigger_define




	uint8 irq_enable;							//enable or disable this exti line, NOTE That this enable would affect both
												//NVIC enable mask and EXT Controller enable mask for this irq
												//This parameter MUST be set based on @ref EXTI_IRQ_define



	void(*p_irq_callback)(void);				//set your c function you want to execute when irq is detected

}Dt_exti_config;

/*********************************Macros Configurations References***********************/
#define EXTI0					0
#define EXTI1					1
#define EXTI2					2
#define EXTI3					3
#define EXTI4					4
#define EXTI5					5
#define EXTI6					6
#define EXTI7					7
#define EXTI8					8
#define EXTI9					9
#define EXTI10					10
#define EXTI11					11
#define EXTI12					12
#define EXTI13					13
#define EXTI14					14
#define EXTI15					15
//@ref EXTI_define

//EXTI0
#define EXTI0PA0                        (Dt_exti_gpio_mapping){EXTI0,GPIOA,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PB0                        (Dt_exti_gpio_mapping){EXTI0,GPIOB,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PC0                        (Dt_exti_gpio_mapping){EXTI0,GPIOC,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PD0                        (Dt_exti_gpio_mapping){EXTI0,GPIOD,GPIO_PIN0,EXTI0_IRQ}


//EXTI1
#define EXTI1PA1                        (Dt_exti_gpio_mapping){EXTI1,GPIOA,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PB1                        (Dt_exti_gpio_mapping){EXTI1,GPIOB,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PC1                        (Dt_exti_gpio_mapping){EXTI1,GPIOC,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PD1                        (Dt_exti_gpio_mapping){EXTI1,GPIOD,GPIO_PIN1,EXTI1_IRQ}


//EXTI2
#define EXTI2PA2                        (Dt_exti_gpio_mapping){EXTI2,GPIOA,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PB2                        (Dt_exti_gpio_mapping){EXTI2,GPIOB,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PC2                        (Dt_exti_gpio_mapping){EXTI2,GPIOC,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PD2                        (Dt_exti_gpio_mapping){EXTI2,GPIOD,GPIO_PIN2,EXTI2_IRQ}


//EXTI3
#define EXTI3PA3                        (Dt_exti_gpio_mapping){EXTI3,GPIOA,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PB3                        (Dt_exti_gpio_mapping){EXTI3,GPIOB,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PC3                        (Dt_exti_gpio_mapping){EXTI3,GPIOC,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PD3                        (Dt_exti_gpio_mapping){EXTI3,GPIOD,GPIO_PIN3,EXTI3_IRQ}


//EXTI4
#define EXTI4PA4                        (Dt_exti_gpio_mapping){EXTI4,GPIOA,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PB4                        (Dt_exti_gpio_mapping){EXTI4,GPIOB,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PC4                        (Dt_exti_gpio_mapping){EXTI4,GPIOC,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PD4                        (Dt_exti_gpio_mapping){EXTI4,GPIOD,GPIO_PIN4,EXTI4_IRQ}


//EXTI5
#define EXTI5PA5                        (Dt_exti_gpio_mapping){EXTI5,GPIOA,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PB5                        (Dt_exti_gpio_mapping){EXTI5,GPIOB,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PC5                        (Dt_exti_gpio_mapping){EXTI5,GPIOC,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PD5                        (Dt_exti_gpio_mapping){EXTI5,GPIOD,GPIO_PIN5,EXTI5_IRQ}


//EXTI6
#define EXTI6PA6                        (Dt_exti_gpio_mapping){EXTI6,GPIOA,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PB6                        (Dt_exti_gpio_mapping){EXTI6,GPIOB,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PC6                        (Dt_exti_gpio_mapping){EXTI6,GPIOC,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PD6                        (Dt_exti_gpio_mapping){EXTI6,GPIOD,GPIO_PIN6,EXTI6_IRQ}


//EXTI7
#define EXTI7PA7                        (Dt_exti_gpio_mapping){EXTI7,GPIOA,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PB7                        (Dt_exti_gpio_mapping){EXTI7,GPIOB,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PC7                        (Dt_exti_gpio_mapping){EXTI7,GPIOC,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PD7                        (Dt_exti_gpio_mapping){EXTI7,GPIOD,GPIO_PIN7,EXTI7_IRQ}


//EXTI8
#define EXTI8PA8                        (Dt_exti_gpio_mapping){EXTI8,GPIOA,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PB8                        (Dt_exti_gpio_mapping){EXTI8,GPIOB,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PC8                        (Dt_exti_gpio_mapping){EXTI8,GPIOC,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PD8                        (Dt_exti_gpio_mapping){EXTI8,GPIOD,GPIO_PIN8,EXTI8_IRQ}


//EXTI9
#define EXTI9PA9                        (Dt_exti_gpio_mapping){EXTI9,GPIOA,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PB9                        (Dt_exti_gpio_mapping){EXTI9,GPIOB,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PC9                        (Dt_exti_gpio_mapping){EXTI9,GPIOC,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PD9                        (Dt_exti_gpio_mapping){EXTI9,GPIOD,GPIO_PIN9,EXTI9_IRQ}


//EXTI10
#define EXTI10PA10                      (Dt_exti_gpio_mapping){EXTI10,GPIOA,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PB10                      (Dt_exti_gpio_mapping){EXTI10,GPIOB,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PC10                      (Dt_exti_gpio_mapping){EXTI10,GPIOC,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PD10                      (Dt_exti_gpio_mapping){EXTI10,GPIOD,GPIO_PIN10,EXTI10_IRQ}


//EXTI11
#define EXTI11PA11                      (Dt_exti_gpio_mapping){EXTI11,GPIOA,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PB11                      (Dt_exti_gpio_mapping){EXTI11,GPIOB,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PC11                      (Dt_exti_gpio_mapping){EXTI11,GPIOC,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PD11                      (Dt_exti_gpio_mapping){EXTI11,GPIOD,GPIO_PIN11,EXTI11_IRQ}


//EXTI12
#define EXTI12PA12                      (Dt_exti_gpio_mapping){EXTI12,GPIOA,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PB12                      (Dt_exti_gpio_mapping){EXTI12,GPIOB,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PC12                      (Dt_exti_gpio_mapping){EXTI12,GPIOC,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PD12                      (Dt_exti_gpio_mapping){EXTI12,GPIOD,GPIO_PIN12,EXTI12_IRQ}


//EXTI13
#define EXTI13PA13                      (Dt_exti_gpio_mapping){EXTI13,GPIOA,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PB13                      (Dt_exti_gpio_mapping){EXTI13,GPIOB,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PC13                      (Dt_exti_gpio_mapping){EXTI13,GPIOC,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PD13                      (Dt_exti_gpio_mapping){EXTI13,GPIOD,GPIO_PIN13,EXTI13_IRQ}


//EXTI14
#define EXTI14PA14                      (Dt_exti_gpio_mapping){EXTI14,GPIOA,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PB14                      (Dt_exti_gpio_mapping){EXTI14,GPIOB,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PC14                      (Dt_exti_gpio_mapping){EXTI14,GPIOC,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PD14                      (Dt_exti_gpio_mapping){EXTI14,GPIOD,GPIO_PIN14,EXTI14_IRQ}


//EXTI15
#define EXTI15PA15                      (Dt_exti_gpio_mapping){EXTI15,GPIOA,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PB15                      (Dt_exti_gpio_mapping){EXTI15,GPIOB,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PC15                      (Dt_exti_gpio_mapping){EXTI15,GPIOC,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PD15                      (Dt_exti_gpio_mapping){EXTI15,GPIOD,GPIO_PIN15,EXTI15_IRQ}

//@ref EXTI_Trigger_define
#define EXTI_TRIGGER_RISING							0
#define EXTI_TRIGGER_FALLING						1
#define EXTI_TRIGGER_FALLING_RISING					2


//@ref EXTI_IRQ_define
#define EXTI_IRQ_ENABLE								1
#define EXTI_IRQ_DISABLE							0


/*************************************APIs Supported by "MCAL EXTI DRIVER"*****************************/

/**================================================================
 * @Fn				-MCAL_exti_gpio_init
 * @brief 			-Initialize EXTI at specific pin and specify mask(EN/DIS) , trigger condition for the irq  and irq callback function
 * @param [in]	 	-exti_config set by @ref EXTI_define , @ref EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			-None
 */
void MCAL_exti_gpio_init(Dt_exti_config* exti_config);
/**================================================================
 * @Fn				-MCAL_exti_gpio_deinit
 * @brief 			-reset EXTI Registers and NVIC corresponding IRQ mask
 * @retval			-None
 */
void MCAL_exti_gpio_deinit(void);
/**================================================================
 * @Fn				-MCAL_exti_gpio_update
 * @brief 			-Update at run time EXTI at specific pin and specify mask(EN/DIS) , trigger condition for the irq  and irq callback function
 * @param [in]	 	-exti_config set by @ref EXTI_define , @ref EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			-None
 */
void MCAL_exti_gpio_update(Dt_exti_config* exti_config);
#endif
