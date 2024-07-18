#include <stdio.h>
#include "string.h"


void Reverse(char str[100]);

void main()
{
	char str[100];
	printf("Enter a sentence: ");
	gets(str);
	Reverse(str);
}

void Reverse(char str[100])
{
	char reverse_str[100];
	int m=strlen(str);
	int j=m;
	for (int i=0; i<m ; i++)
	{
		
		reverse_str[j-1]=str[i];
		j--;
	} 
	
	printf("%s",reverse_str);
	
}


