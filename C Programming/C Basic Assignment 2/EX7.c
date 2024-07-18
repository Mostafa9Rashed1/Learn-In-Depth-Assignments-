# include "stdio.h"

void main ()
{
	int x,factorial=1;
	printf("Enter an integer: ");
	scanf("%d",&x);
	if (x>0)
	{
		for (int i=x ;i>0 ;i--)
		{
			factorial = factorial*i;	
		}
		printf("factorial= %d",factorial);
	} 
	else if(x==0)
	{
		factorial=1;
		printf("factorial= %d",factorial);
		
	}
	else
	{
		printf("Error!!!");
	}
	
}