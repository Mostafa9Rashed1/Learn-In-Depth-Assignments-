#include <stdio.h>

void main()
{
	char arr[5],rvs_arr[5];
	char *ptr=NULL;
	char *rvs_ptr=NULL;
	printf("Input 5 number of elements in the array : \n");
	for(int i=0;i<5;i++)
	{
		printf("element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	ptr=arr;
	rvs_ptr=rvs_arr;
	if (ptr !=NULL && rvs_arr !=NULL)
	{
		for (int i=0;i<5;i++)
		{
			*ptr;
			ptr++;
		}
		for (int i=0;i<5;i++)
		{
			ptr--;
			*rvs_ptr=*ptr;
			rvs_ptr++;
		}
		printf("The elements of reverse array are :\n");
		for (int i=0;i<5;i++)
		{
			printf("element  %d : %d\n",i+1,rvs_arr[i]);
		}
		
	}
	else
	{
		printf("ERROR!!! NULL pointer");
	}
}