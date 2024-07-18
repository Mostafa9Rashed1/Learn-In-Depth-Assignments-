# include "stdio.h"

void main()
{
	float arr1[2][2];
	float arr2[2][2];
	
	
	printf("Enter the element of 1st matrix :\n");
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
		printf("Enter a%d%d: ",i+1,j+1);
		scanf("%f",&arr1[i][j]);
		}
	}
		printf("Enter the element of 2nd matrix :\n");
		for (int i=0;i<2;i++)
		{
			for (int j=0;j<2;j++)
			{
				printf("Enter a%d%d: ",i+1,j+1);
				scanf("%f",&arr2[i][j]);
			}	
	}
	
	
	printf("Sum of Matrix:\n");
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("\t%f",(arr1[i][j]+arr2[i][j]));
			
		}
		printf("\n");
	}
		
}