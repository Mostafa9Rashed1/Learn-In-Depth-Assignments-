#include <stdio.h>

typedef struct
{
	float re;
	float imag;
}complex_t ;

void main ()
{
	complex_t number1, number2, sum;
	printf("for 1st complex number\n");
	printf("Enter real and imaginary respectively : " );
	scanf("%f %f",&number1.re,&number1.imag);
	
	printf("for 2nd complex number\n");
	printf("Enter real and imaginary respectively : " );
	scanf("%f %f",&number2.re,&number2.imag);
	
	sum.re=number1.re+number2.re;
	sum.imag=number1.imag+number2.imag;
	
	printf("Sum = %.2f+%.2fi ",sum.re,sum.imag );
}