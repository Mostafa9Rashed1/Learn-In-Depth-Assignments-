# include "stdio.h"

void main ()
{
	float a, b ;
	char operation;
	printf("Enter operands either + or - or * or / ");
	scanf("%c",&operation);
	printf("Enter two operants: ");
	scanf("%f%f",&a,&b);
	if (operation == '+')
	{
		printf("%f + %f = %f ",a,b,a+b);
	} 
	else if(operation == '-')
	{
		printf("%f - %f = %f ",a,b,a-b);
	}
	else if(operation == '*')
	{
		printf("%f * %f = %f ",a,b,a*b);
	}
	else if(operation == '/')
	{
		printf("%f / %f = %f ",a,b,a/b);
	}
	else
	{
		printf("Error!!");
	}
}