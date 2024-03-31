/*
startup.c for cortex-m3 -- ALI KHALED
*/
#include "Platfrom_Types.h"
extern uint32 stack_top;
void Reset_Handler();
extern int main(void);
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;
void Bus_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;
uint32 vectors_arr[] __attribute__((section(".vectors"))) = {
	(uint32)&stack_top,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&H_Fault_Handler,
	(uint32)&Bus_Fault_Handler,
	(uint32)&Usage_Fault_Handler,
};
extern uint32 _E_text;
extern uint32 _S_text;
extern uint32 _E_data;
extern uint32 _S_data;
extern uint32 _E_bss;
extern uint32 _S_bss;

void Reset_Handler()
{	

	/*
	copyt data section from flash to ram
	*/
	uint32 data_size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8* Pdata_src = (uint8*)&_E_text; //or _E_data it is the same
	uint8* Pdata_dest = (uint8*)&_S_data;
	uint32 i;
	for(i = 0; i< data_size; i++)
	{
		*Pdata_dest = *Pdata_src;
		Pdata_dest++;
		Pdata_src++; 
	}
	
	/*
	init bss section at sram
	*/
	uint32 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	uint8* Pbss_dest = (uint8*)&_S_bss;
	for(i = 0; i< bss_size; i++)
	{
		*Pbss_dest = (uint8)0; 
		 Pbss_dest++;
	}
		
	/*
	jump to main
	*/
	main();
	
}
