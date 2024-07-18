#include <stdio.h>

void Power_num(int num,int power);

void main()
{
	int base_number, power_number;
	printf("Enter base number: ");
	scanf("%d",&base_number);
	printf("Enter power number: ");
	scanf("%d",&power_number);
	Power_num(base_number,power_number);
}

void Power_num(int num,int power)
{
	int result_val=1;
	if (power>=0)
	{
		for (int i=1;i<=power;i++)
		{
			result_val=result_val*num;
		}
		printf(" %d^%d = %d",num,power,result_val);
	} 
	else
	{
		printf("Error!!the power must be positive ");
	}
	
}


