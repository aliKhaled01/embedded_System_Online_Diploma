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
	 _E_text = . ;
	}> flash
	
    .data :
	{
	_S_data = . ;
	 *(*.data*)
	 *(*.data.*)
	_E_data = . ;
	}> sram AT> flash

    .bss :
	{
	_S_bss = . ;
	*(*.bss*)
	_E_bss = . ;
	. = ALIGN(4) ;
	. = . + 0x1000 ;
	_heap_end = . ;
	. = ALIGN(4) ;
	. = . + 0x1000 ;
	stack_top = . ;
	}> sram
}
