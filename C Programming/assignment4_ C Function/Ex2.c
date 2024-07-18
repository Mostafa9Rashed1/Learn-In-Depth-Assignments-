#include <stdio.h>

void Factorial(int num);

void main()
{
	int number ;
	printf("Enter positive number: ");
	scanf("%d",&number);
	Factorial(number);
	
}

void Factorial(int num)
{
	int fact_val=1;
	if (num>=0)
	{
		
		for (int i=num ; i>=1;i--)
		{
			fact_val=fact_val*i;
		}
		printf("Factorial of %d = %d",num,fact_val);
	}
	else
	{
		printf("The number must be positive");
	}
}
