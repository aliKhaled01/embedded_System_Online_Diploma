#include "Platfrom_Types.h"
#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800
#define RCC_APB2ENR *((volatile uint32*) (RCC_BASE +0x18))
#define GPIO_CRH *((volatile uint32*) (GPIO_BASE +0x04))
#define RCC_IOPAEN (1<<2)
#define GPIOA13 (1UL<<13)
#define RCC_CFGR *((volatile uint32*) (RCC_BASE +0x04))
typedef union
{
	uint32 all_fields;
	struct
	{	
		uint32 reserved:13;
		uint32 P_13:1;
	}Pin;
}R_ODR_t;
volatile R_ODR_t * R_ODR = (volatile R_ODR_t* ) (GPIO_BASE+0x0C);
void clock_init()
{
/*HCLK divided by 4 (prescalar) APB1*/
RCC_CFGR|=(1<<11);
RCC_CFGR&=~(1<<12);
RCC_CFGR|=(1<<13);

/*HCLK divided by 2 (prescalar) APB2*/
RCC_CFGR|=(0b100<<8);

/*Enable Clock for APB Bus*/
RCC_APB2ENR|=RCC_IOPAEN;	
}
int main(void)
{
clock_init();
GPIO_CRH &=0xFF0FFFFF;
GPIO_CRH |=0x00200000;
int i = 0 , j =0;
while(1)
{
	R_ODR->Pin.P_13 = 1;
	for(;i<5000;i++);
	R_ODR->Pin.P_13 = 0;
	for(;j<5000;j++);
}
}
