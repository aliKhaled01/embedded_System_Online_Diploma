/*
linker script for cortex - ALI KHALED
*/

MEMORY
{
flash(rx) : ORIGIN = 0x8000000 , LENGTH = 128k 
sram(rwx) : ORIGIN = 0x2000000 , LENGTH = 20k 
}

SECTIONS
{
    .text : 
	{
	 *(*.vectors*)
	 *(*.text*)
	 *(*.rodata*)
	}> flash

    .data :
	{
	 *(*.data*)
	}> flash

    .bss :
	{
	*(*.bss*)
	}> sram
}
