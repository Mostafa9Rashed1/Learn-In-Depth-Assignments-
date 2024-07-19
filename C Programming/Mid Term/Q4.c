#include "stdio.h"
#include <string.h>

void reverse(char Numbers_bits[100])
{
	int n =strlen(Numbers_bits);
	char numbers_reverse[100];
	
	for (int i=0; Numbers_bits[i] !=0 ;i++)
	{
			numbers_reverse[i]=	Numbers_bits[n-i-1];
		
	}
	
	printf("The reverse string is %s\n",numbers_reverse);
	
}



void main()
{
	char string[100];
	char string_reverse[100];
	int n, flag=0 , mid;
	printf("Enter the Number: ");
	gets(string);
	reverse(string);
	
}