# include "stdio.h"

void main ()
{
	float x , y , z , max;
	printf("Enter Three Numbers: ");
	scanf("%f%f%f",&x,&y,&z);
	max= x > y && x > z ? x : y > z ? y : z;   
	
	printf("Largest number =%f",max); 
}