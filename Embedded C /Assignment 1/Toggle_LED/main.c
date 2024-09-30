
#include "platform.h"
typedef union {
	uint32_t all_pins;
	struct{
		uint32_t pin0:1;
		uint32_t pin1:1;
		uint32_t pin2:1;
		uint32_t pin3:1;
		uint32_t pin4:1;
		uint32_t pin5:1;
		uint32_t pin6:1;
		uint32_t pin7:1;
		uint32_t pin8:1;
		uint32_t pin9:1;
		uint32_t pin10:1;
		uint32_t pin11:1;
		uint32_t pin12:1;
		uint32_t pin13:1;
		uint32_t pin14:1;
		uint32_t pin15:1;
		uint32_t pin16:1;
		uint32_t pin17:1;
		uint32_t pin18:1;
		uint32_t pin19:1;
		uint32_t pin20:1;
		uint32_t pin21:1;
		uint32_t pin22:1;
		uint32_t pin23:1;
		uint32_t pin24:1;
	};
} reg;
#define RCC_base_add 0x40021000
#define GPIO_base_add 0x40010800
 volatile  reg* APB2ENR = (volatile  reg*)(RCC_base_add+0X18);
 volatile  reg* CHR = (volatile  reg*)(GPIO_base_add+0X04);
 volatile  reg* ODR = (volatile  reg*)(GPIO_base_add+0X0C);
int main(void)
{   volatile int i ;
	APB2ENR->pin2=1;
	CHR->all_pins=0;
	CHR->pin21=1;
	while(1)
	{
		ODR->pin13=1;
		for(i=0;i<50000;i++);
		ODR->pin13=0;
		for(i=0;i<50000;i++);
	}
	for(;;);
}
