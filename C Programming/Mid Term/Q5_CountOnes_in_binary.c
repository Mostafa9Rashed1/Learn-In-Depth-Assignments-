#include <stdio.h>

int countounes (int num)
{
	int count;
	while (num>0)
	{
		if (num%2 == 1)
		{
			count++;
		}
		num /=2;
	}
	return count;
}

void main()
{
	int number,flag=0;
	printf("Enter the number: ");
	scanf("%d",&number);
	int onesCount=countounes(number);

	printf("Number of ones in the binary representation of %d is %d.\n", number, onesCount);

	
}