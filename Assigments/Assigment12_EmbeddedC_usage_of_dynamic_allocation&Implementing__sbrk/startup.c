/*
startup.c for cortex-m3 -- ALI KHALED
*/
#include "Platfrom_Types.h"
void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
void Reset_Handler();
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;
void Bus_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;
uint32 vectors_arr[] __attribute__((section(".vectors"))) = {
	(uint32)0x20001000,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&H_Fault_Handler,
	(uint32)&Bus_Fault_Handler,
	(uint32)&Usage_Fault_Handler,
};
void Reset_Handler()
{
	main();
}
