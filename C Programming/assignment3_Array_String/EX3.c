# include "stdio.h"

void main()
{
	int arr[10][10];
	int n,m;
	printf("Enter rows and column of matrix: ");
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			printf("Enter elements a%d%d: ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}	
	}
	printf("Entered Matrix:\n");
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			
			printf("\t%d",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("Transpose Matrix:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			
			printf("\t%d",arr[j][i]);
		}
		printf("\n");
	}
	
}