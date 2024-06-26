#include "Platfrom_Types.h"

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32*) (RCC_BASE +0x18)
#define RCC_IOAPAEN (1<<2)


#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32*) (GPIOA_BASE +0x04)
#define GPIOA_ODR *(volatile uint32*) (GPIOA_BASE +0x0C)
#define GPIOA_CRL *(volatile uint32*) (GPIOA_BASE +0x00)
#define GPIOA_IDR *(volatile uint32*) (GPIOA_BASE +0x08)
#define GPIOA13 (1UL<<13)

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRH *(volatile uint32*) (GPIOB_BASE +0x04)
#define GPIOB_ODR *(volatile uint32*) (GPIOB_BASE +0x0C)
#define GPIOB_CRL *(volatile uint32*) (GPIOB_BASE +0x00)
#define GPIOB_IDR *(volatile uint32*) (GPIOB_BASE +0x08)
#define RCC_IOBPAEN (1<<3)
void clock_init(void)
{
	/*Enable the clock for GPIOA  on APB2 BUS*/
	RCC_APB2ENR|=RCC_IOAPAEN;

	/*Enable the clock for GPIOB  on APB2 BUS*/
	RCC_APB2ENR|=RCC_IOBPAEN;

}
void GPIO_init(void)
{
	GPIOA_CRL = 0 ; // As from TRM is has init value 0x4444 4444
	GPIOB_CRL = 0 ; // As from TRM is has init value 0x4444 4444

	/*
	 * PA1 Input , Floating
	 */
	GPIOA_CRL&=~(0b11<<4);
	GPIOA_CRL|=(0b01<<6);

	/*
	 * PB1 Output , Push Pull mode
	 */

	GPIOB_CRL|=(0b01<<4);
	GPIOB_CRL&=~(0b11<<6);
	/*
	 * PA13 Input , Floating
	 */
	GPIOB_CRH&=~(0b11<<20);
	GPIOB_CRH|=(0b01<<22);

	/*
	 * PB13 Output , Push Pull mode
	 */
	GPIOB_CRL|=(0b01<<20);
	GPIOB_CRL&=~(0b11<<22);
}
void my_wait(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<255;j++);
	}
}
int main(void)
{
clock_init();
GPIO_init();

while(1)
{
	/*
	 * Check PA1  , connected to external PUR
	 */
	if( ((GPIOB_IDR &(1<<1))>>1) == 0) //Pressed
	{
		/*
		 * Toggle Led at PB1
		 */
		GPIOB_ODR^=(1<<1);
		while(((GPIOB_IDR &(1<<1))>>1) == 0); /*Single Pressing*/

	}

	/*
	 * Check PA13  , connected to external PDR
	 */
	if( ((GPIOB_IDR &(1<<13))>>13) == 1) //Pressed
	{
		/*
		 * Toggle Led at PB1
		 */
		GPIOB_ODR^=(1<<13);
	}
	my_wait(1);
}

}
