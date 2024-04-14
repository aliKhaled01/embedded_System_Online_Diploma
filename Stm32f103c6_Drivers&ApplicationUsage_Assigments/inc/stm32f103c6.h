#ifndef STM32F103C6_H
#define STM32F103C6_H
/*********************************INCLUDES**************************************/
#include "platform_types.h"
/***************************MEMORIES BASE ADDRESSES  ***************************/
#define FLASH_MEMORY_BASE_ADDRESS 								0x08000000UL
#define SYSTEM_MEMORY_BASE_ADDRESS 								0x1FFFF000UL
#define SRAM_MEMORY_BASE_ADDRESS 								0x20000000UL
#define PERIPHRALS_BASE_ADDRESS 								0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHRALS_BASE_ADDRESS 				0xE0000000UL
//NVIC register map
#define NVIC_BASE_ADDRESS										0xE000E100UL
#define NVIC_ISER0												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x0))
#define NVIC_ISER1												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x4))
#define NVIC_ISER2												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x8))
#define NVIC_ICER0												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x80))
#define NVIC_ICER1												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x84))
#define NVIC_ICER2												*((volatile uint32*)(NVIC_BASE_ADDRESS+0x88))

/***************************PERIPHERALS BASE ADDRESSES AT ABP2 BUS ***************************/

/*
 * GPIO
 */
#define GPIOA_BASE_ADDRESS 											0x40010800
#define GPIOB_BASE_ADDRESS 											0x40010C00
#define GPIOC_BASE_ADDRESS 											0x40011000
#define GPIOD_BASE_ADDRESS 											0x40011400
#define GPIOE_BASE_ADDRESS 											0x40011800

/*
 * EXT INTERRUPT CONTROLLER
 */
#define EXTI_BASE_ADDRESS											0x40010400

/*
 * AFIO
 */
#define AFIO_BASE_ADDRESS											0x40010000

/***************************PERIPHERALS BASE ADDRESSES AT AHB BUS  ***************************/

/*
 * RCC
 */
#define RCC_BASE_ADDRESS 										0x40021000

/********************************PERIPHERALS REGISTERS*******************************************/

/*
 * GPIO
 */
typedef struct
{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;
}Dt_GPIO;

/*
 * RCC
 */
typedef struct
{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
}Dt_RCC;

/*
 * EXTI
 */
typedef struct
{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}Dt_EXTI;

/*
 * AFOI
 */
typedef struct
{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];
	uint32 			reserved;
	volatile uint32 MAPR2;		//0x1c offset
}Dt_AFIO;

/********************************PERIPHERALS ACCESS *******************************************/
#define GPIOA 							 ((Dt_GPIO*)GPIOA_BASE_ADDRESS)
#define GPIOB 							 ((Dt_GPIO*)GPIOB_BASE_ADDRESS)
#define GPIOC 							 ((Dt_GPIO*)GPIOC_BASE_ADDRESS)
#define GPIOD 							 ((Dt_GPIO*)GPIOD_BASE_ADDRESS)
#define GPIOE 							 ((Dt_GPIO*)GPIOE_BASE_ADDRESS)
#define RCC								 ((Dt_RCC*)RCC_BASE_ADDRESS)
#define AFIO							 ((Dt_AFIO*)AFIO_BASE_ADDRESS)
#define EXTI							 ((Dt_EXTI*)EXTI_BASE_ADDRESS)

/***********************************CLOCK ENABLE MACROS******************************************************/
#define RCC_GPIOA_CLOCK_EN()	(RCC->APB2ENR|=(1<<2))
#define RCC_GPIOB_CLOCK_EN()	(RCC->APB2ENR|=(1<<3))
#define RCC_GPIOC_CLOCK_EN()	(RCC->APB2ENR|=(1<<4))
#define RCC_GPIOD_CLOCK_EN()	(RCC->APB2ENR|=(1<<5))
#define RCC_GPIOE_CLOCK_EN()	(RCC->APB2ENR|=(1<<6))
#define RCC_AFIO_CLOCK_EN()			(RCC->APB2ENR|=(1<<0))

/***********************************NVIC ENABLE/DISABLE MACROS******************************************************/
#define NVIC_IRQ6_EXTI0_ENABLE()		(NVIC_ISER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE()		(NVIC_ISER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE()		(NVIC_ISER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE()		(NVIC_ISER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE()		(NVIC_ISER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_9_ENABLE()		(NVIC_ISER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_15_ENABLE()	(NVIC_ISER1|=(1<<8))

#define NVIC_IRQ6_EXTI0_DISABLE()		(NVIC_ICER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE()		(NVIC_ICER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE()		(NVIC_ICER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE()		(NVIC_ICER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE()		(NVIC_ICER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_9_DISABLE()	(NVIC_ICER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_15_DISABLE()	(NVIC_ICER1|=(1<<8))


/********************************Interrupt Vector Table( IVT) *******************************************/
//IRQs - EXTI
#define EXTI0_IRQ				6
#define EXTI1_IRQ				7
#define EXTI2_IRQ				8
#define EXTI3_IRQ				9
#define EXTI4_IRQ				10
#define EXTI5_IRQ				23
#define EXTI6_IRQ				23
#define EXTI7_IRQ				23
#define EXTI8_IRQ				23
#define EXTI9_IRQ				23
#define EXTI10_IRQ				40
#define EXTI11_IRQ				40
#define EXTI12_IRQ				40
#define EXTI13_IRQ				40
#define EXTI14_IRQ				40
#define EXTI15_IRQ				40

/***********************************Generic MACROS******************************************************/
#define GET_CORRESPONDING_EXTI_VALUE(x) 	( (x==GPIOA)?0:\
		(x==GPIOB)?1:\
		(x==GPIOC)?2:\
		(x==GPIOD)?3:0 )
#endif
