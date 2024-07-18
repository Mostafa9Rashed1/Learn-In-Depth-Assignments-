#include "stdio.h"
#include <string.h>

void main()
{
	char string[100];
	char string_reverse[100];
	int n, flag=0 , mid;
	printf("Enter a string: ");
	gets(string);
	n =strlen(string);
	
	
		for (int i=0; string[i] !=0 ;i++)
		{	
			string_reverse[i]=string[n-i-1];
			flag++;
		}
		printf("%d\n",flag);
		printf("The reverse string is %s\n",string_reverse);
	
			
}