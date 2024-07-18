# include "stdio.h"

void main()
{
	int arr[100];
	int n, search_num, flag=0;
	printf("Enter No. of element: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("\t");
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be search: ");
	scanf("%d",&search_num);
	
	for (int i=0;i<n;i++)
	{
		if (arr[i]==search_num)
		{
			printf("Number found at Location = %d",i+1);
			break;	
		} 
		flag++;	
	}
	if (flag>=n)
	{
		printf("The Number is not exist in the Array");
	}
	
}