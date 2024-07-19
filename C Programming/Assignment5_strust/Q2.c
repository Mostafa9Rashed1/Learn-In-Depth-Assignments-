#include <stdio.h>

typedef struct
{
	float feet;
	float inches;
}distance_t ;

void main ()
{
	distance_t distance1, distance2, sum;
	printf("Enter information for distance 1st: \n" );
	printf("Enter Feet: ");
	scanf("%f",&distance1.feet);
	printf("Enter inches: ");
	scanf("%f",&distance1.inches);
	
	printf("Enter information for distance 2st: \n" );
	printf("Enter Feet: ");
	scanf("%f",&distance2.feet);
	printf("Enter inches: ");
	scanf("%f",&distance2.inches);
	
	sum.feet=distance1.feet+distance2.feet;
	sum.inches=distance1.inches+distance2.inches;
	
	if (sum.inches>12.0)
	{
		sum.inches -= 12.0;
		++sum.feet;
	}
	
	printf("Sum of distances= %.2f' - %.2f\" ",sum.feet,sum.inches );	
}