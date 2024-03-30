#include "uart.h"

void Uart_Send_string(unsigned char * str)
{
	while(*str != '\0')
	{
		UART0DR =  (unsigned int)(*str);
		str++;
	}
}