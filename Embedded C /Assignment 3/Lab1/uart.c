#include "uart.h"
#define UART0DR		*((volatile unsigned int*)((volatile unsigned int*)0x101f1000))

void Uart_Send_String(unsigned char* Ptr_string )
{
	while (*Ptr_string !='\0')
	{
		UART0DR = (unsigned int )(*Ptr_string);
		Ptr_string++;
	}
	
}
