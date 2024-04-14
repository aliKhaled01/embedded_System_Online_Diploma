#ifndef STM32F103C6_H
#define STM32F103C6_H
/*********************************INCLUDES**************************************/
#include "Platfrom_Types.h"
/***************************MEMORIES BASE ADDRESSES  ***************************/
#define FLASH_MEMORY_BASE_ADDRESS 								0x08000000UL
#define SYSTEM_MEMORY_BASE_ADDRESS 								0x1FFFF000UL
#define SRAM_MEMORY_BASE_ADDRESS 								0x20000000UL
#define PERIPHRALS_BASE_ADDRESS 								0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHRALS_BASE_ADDRESS 				0xE0000000UL

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
	volatile uint32 RSTR;
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
	volatile uint32 EXTICR1;
	volatile uint32 EXTICR2;
	volatile uint32 EXTICR3;
	volatile uint32 EXTICR4;
	volatile uint32 EXTICR5;	//0x14 offset
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
#define EXTI							 ((Dt_RCC*)EXTI_BASE_ADDRESS)

/***********************************CLOCK ENABLE MACROS******************************************************/
#define RCC_GPIOA_CLOCK_EN()	(RCC->APB2ENR|=(1<<2))
#define RCC_GPIOB_CLOCK_EN()	(RCC->APB2ENR|=(1<<3))
#define RCC_GPIOC_CLOCK_EN()	(RCC->APB2ENR|=(1<<4))
#define RCC_GPIOD_CLOCK_EN()	(RCC->APB2ENR|=(1<<5))
#define RCC_GPIOE_CLOCK_EN()	(RCC->APB2ENR|=(1<<6))
#define AFIO_CLOCK_EN()			(RCC->APB2ENR|=(1<<0))


#endif
