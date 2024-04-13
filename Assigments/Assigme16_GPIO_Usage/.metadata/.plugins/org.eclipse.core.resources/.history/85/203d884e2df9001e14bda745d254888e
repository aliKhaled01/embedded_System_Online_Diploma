#include "Platfrom_Types.h"

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32*) (RCC_BASE +0x18)
#define RCC_IOPAEN (1<<2)
#define RCC_AFIOPAEN (1<<0)

#define GPIOA_BASE 0x40010800
#define GPIO_CRH *(volatile uint32*) (GPIOA_BASE +0x04)
#define GPIO_ODR *(volatile uint32*) (GPIOA_BASE +0x0C)
#define GPIO_CRL *(volatile uint32*) (GPIOA_BASE +0x00)
#define GPIOA13 (1UL<<13)
#define AFIO_BASE   0x40010000
#define AFIO_EXTICR1	*(volatile uint32*) (AFIO_BASE +0x08)

#define EXTI_BASE 0x40010400
#define EXTI_IMR *(volatile uint32*) (EXTI_BASE +0x00)
#define EXTI_RTSR *(volatile uint32*) (EXTI_BASE +0x08)
#define EXTI_PR *(volatile uint32*) (EXTI_BASE +0x14)
#define NVIC_EXTI0 *(volatile uint32*) (0xE000E100)
void clock_init(void)
{
	/*Enable the clock for GPIOA  on APB2 BUS*/
	RCC_APB2ENR|=RCC_IOPAEN;

	/*Enable the clock for AFIO on APB2 BUS*/
	RCC_APB2ENR|=RCC_AFIOPAEN;
}
void GPIO_init(void)
{
	/*Pin 13 PORTA is output */
	GPIO_CRH &=0xFF0FFFFF;
	GPIO_CRH |=0x00200000;

	/*
	 * Pin0 for PORTA  input , floating
	 */
	GPIO_CRL|=(1<<2);
}
void exti0_init(void)
{
	/*
	 enable the interrupt request irq0
	 it is a must , so EXTI can sense the irq
	 */
	EXTI_IMR |= (1<<0);
	/*
	 rising trigger detection configuration
	 */
	EXTI_RTSR|=(1<<0);

	/*
	 * configure PA0 to be used for EXTI0
	 */
	AFIO_EXTICR1|=(0b000<<0);

	/*
	 *Enable the NVIC irq 6 (ext0 is mapped to irq16 from vector table) ,
	 * so it can pass to the cpu
	 */
	NVIC_EXTI0|=(1<<6);
}
int main(void)
{
clock_init();
GPIO_init();
exti0_init();
while(1);
}

/*IRQ for exti0 is handling , rising edge detected from EXTI detection cricuit */
/*Interrupt Handler for exti0*/
void EXTI0_IRQHandler(void)
{

	/*
	 * Toggle pin 13 for port A
	 */
	GPIO_ODR^=(1<<13);



	/*
	 * clear the pending irq for line 0 , to avoid infinte irq handling , write 1 to clear
	 */
	EXTI_PR|=(1<<0);
}
