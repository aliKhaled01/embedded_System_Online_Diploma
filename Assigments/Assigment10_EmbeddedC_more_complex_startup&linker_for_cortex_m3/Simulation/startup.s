/*
startup_cortexM3.s ALI KHALED
*/

//SRAM start 0x20000000

.section .vectors

.word 0x20001000 /* stack top pointer*/
.word _reset  /* reset */
.word _VECTOR_HANDLER /*NMI*/
.word _VECTOR_HANDLER	/*Hard Fault*/
.word _VECTOR_HANDLER	/*MM Fault*/
.word _VECTOR_HANDLER	/*Bus Fault*/
.word _VECTOR_HANDLER	/*Usage Fault*/
.word _VECTOR_HANDLER	/*RESERVED*/
.word _VECTOR_HANDLER	/*RESERVED*/
.word _VECTOR_HANDLER	/*RESERVED*/
.word _VECTOR_HANDLER	/*RESERVED*/
.word _VECTOR_HANDLER	/*Debug reserved*/
.word _VECTOR_HANDLER	/*RESERVED*/
.word _VECTOR_HANDLER	/*PendSV*/
.word _VECTOR_HANDLER	/*SysTick*/
.word _VECTOR_HANDLER	/*IRQ0*/
.word _VECTOR_HANDLER	/*IRQ1*/
.word _VECTOR_HANDLER	/*IRQ2*/
.word _VECTOR_HANDLER	/*...*/

.section .text
_reset:
	bl main
	b .
.thumb_func

_VECTOR_HANDLER:
	b _reset