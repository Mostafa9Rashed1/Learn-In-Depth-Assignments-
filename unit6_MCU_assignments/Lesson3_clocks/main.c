#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define GPIOA_BASE 0x40010800
volatile unsigned int* GPIOA_CRH=(volatile unsigned int *)0x40010804;
volatile unsigned int* GPIOA_ODR=(volatile unsigned int *)0x4001080c;
volatile unsigned int* RCC_APB2_ENR=(volatile unsigned int *)0x40021018;
volatile unsigned int* RCC_CR=(volatile unsigned int *)0x40021000; // CONTROL REGISTER
volatile unsigned int* RCC_CFGR=(volatile unsigned int *)0x40021004; // Configuration register

/*void clock_init_lab2()
{
	// lab 2
	//RCC_CR by default enables HSI clock source
	//RCC_CFGR by default reset value selects HSI as clock source
	//	*RCC_CFGR |=(0b0000<<4); // AHB NOT divided 8 Mhz
 *RCC_CFGR |= (1<<10); // APB1 divided by 2
 *RCC_CFGR |=((1<<11)|(1<<13)); // APB2 divided by 4
}*/
void clock_init_lab3()
{   // RCC_CFGR bit 16 by default is 0 to select HSI as input to PLL


	*RCC_CFGR |=(1<<1); // select PLL as system clock
	*RCC_CFGR |=(1<<10); // divide APB1 prescaler by 2 to make APB1 clock by 32/2=16 MHZ
	*RCC_CFGR |=(1<<13)|(1<<11); // divide APB2 prescaler by 4 to make APB1 clock by 32/4=8 MHZ
	*RCC_CFGR |=(1<<20); // adjust PLL MULL to MUL by 8 to make sysclck is 4*8=32 MHZ
	*RCC_CFGR |=(1<<19);
	*RCC_CR |=(1<<24); // Enable PLL
}

int main(void)
{ //  clock_init_lab2();
	clock_init_lab3();
	*GPIOA_CRH &= 0xFF0FFFFF;
	*GPIOA_CRH |= 1<<21;
	*RCC_APB2_ENR |=1<<2;

	int i;
	while(1)
	{
		*GPIOA_ODR |=1<<13;
		for(i=0;i<5000;i++);
		*GPIOA_ODR &= ~(1<<13);
		for(i=0;i<5000;i++);

	}

}
