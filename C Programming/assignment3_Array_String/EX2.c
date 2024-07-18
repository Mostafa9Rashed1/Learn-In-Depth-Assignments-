# include "stdio.h"

void main()
{
	float arr[100];
	float sum=0 , average;
	int n ;
	printf("Enter the number of data: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++ )
	{
		printf("%d. Enter number: ",i+1);
		scanf("%f",&arr[i]);
		sum =sum +arr[i];
	}
	
	average =sum/n;
	printf("The average= %.3f",average);

}