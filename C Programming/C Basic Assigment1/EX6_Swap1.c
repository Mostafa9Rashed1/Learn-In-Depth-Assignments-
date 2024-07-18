# include "stdio.h"

void main ()
{
	float x , y , temp;
	printf("Enter value of a:");
	scanf("%f",&x);
	printf("Enter value of b:");
	scanf("%f",&y);
	temp=x;
	x=y;
	y= temp;
	printf("After swapping, Value of a = %f\n",x);
	printf("After swapping, Value of b = %f\n",y);
}
