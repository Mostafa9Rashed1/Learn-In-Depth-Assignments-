#include "uart.h"
unsigned char string_buffer[100]="Mostafa_Rashed";
unsigned char string_buffer2[100]="Rashed_Kamel";

	

void main()
{
	Uart_Send_String(string_buffer);
}
