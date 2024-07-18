# include "stdio.h"

void main()
{
	int arr[100];
	int n, insert_num, Location;
	printf("Enter No. of element: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("\t");
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted : ");
	scanf("%d",&insert_num);	
	printf("Enter the Location : ");
	scanf("%d",&Location);
	arr[Location-1]=insert_num;
	
	
	for (int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
		
	}
}