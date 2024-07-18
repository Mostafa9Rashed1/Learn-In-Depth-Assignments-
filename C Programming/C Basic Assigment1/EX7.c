# include "stdio.h"

void main ()
{
	float x , y ;
	printf("Enter value of a:");
	scanf("%f",&x);
	printf("Enter value of b:");
	scanf("%f",&y);
	/* first method
	x=x+y;
	y=x-y;
	x=x-y;*/
	// anther method 
	x=x*y;
	y=x/y;
	x=x/y;
	printf("After swapping, Value of a = %f\n",x);
	printf("After swapping, Value of b = %f\n",y);
	
}
