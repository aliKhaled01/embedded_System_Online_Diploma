#include "uart.h"
unsigned char str_buff[100] = "Learn In Depth Ali Khaled";
int main(void)
{
	Uart_Send_string(str_buff);
	return 0;
}