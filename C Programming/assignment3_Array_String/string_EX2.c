#include "stdio.h"
#include <string.h>

void main()
{
	char string[100];
	int flag=0;
	printf("Enter a string: ");
	gets(string);

	for (int i=0; string[i]!=0;i++)
	{
		flag++;
	}
	printf("Length of string: %d",flag);	
	
}