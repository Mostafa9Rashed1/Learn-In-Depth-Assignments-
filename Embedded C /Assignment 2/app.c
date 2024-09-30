#include "uart.h"


unsigned char string_buffer1[100]="learn-in-depth<Mostafa Rashed>";
unsigned char const string_buffer2[100]="learn-in-depth<Rashed Kamel>";


void main(void)
{
uart_send_string(string_buffer1);
}

