

typedef volatile unsigned int  vuint32_t;
#include <stdint.h>

// register address

#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define RCC_APB2ENR		*(volatile uint32_t *)(RCC_BASE+0x18)
#define GPIOA_CRH		*(volatile uint32_t *)(GPIOA_BASE+0x04)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA_BASE+0x0c)

// Bit fields
#define RCC_IOPAEN		(1<<2)
#define GPIOA13			(1UL<<13)

typedef union {
			vuint32_t		all_fields;
			struct {
				vuint32_t	reserved:13;
				vuint32_t	P_13:1;
				}Pin;
				
			}R_ODR_t;
			
			
volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0c) ;

int main(void)
{
	volatile int y;
	volatile int i;
	RCC_APB2ENR |=RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while (1)
	{
		
		for (i=0;i<50000;i++);   // time delay
		R_ODR->Pin.P_13 = 1;
		
		for (y=0;y<50000;y++);  // time delay
		R_ODR->Pin.P_13 = 0;
	}
	return 0;

}
				
						