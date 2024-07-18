# include "stdio.h"

void main ()
{
	int x,sum;
	printf("Enter an integer: ");
	scanf("%d",&x);
	for (int i=0 ;i<=x ;i++)
	{
		sum = sum+i;
	}
	printf("Sum= %d",sum);
		
}