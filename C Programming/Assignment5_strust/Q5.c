#include <stdio.h>
#define PI 3.14
#define AREA(r)	(PI*r*r)
void main ()
{
	float radius;
	printf("Enter the Radius: ");
	scanf("%f",&radius);
	float area=AREA(radius);
	printf("Area=%.2f",area);
}