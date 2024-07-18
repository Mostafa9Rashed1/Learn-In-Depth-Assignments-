#include "stdio.h"
#include <string.h>

void main()
{
	char string[100];
	int n , flag=0;
	char char_freq;
	printf("Enter a string: ");
	gets(string);
	printf("Enter a character to find frequency: ");
	scanf("%c",&char_freq);
	n =strlen(string);
	
	for (int i=0; i<n;i++)
	{
		if (char_freq==string[i])
		{
			flag++;
		}
	}
	if (flag>0)
	{
	 printf("Frequency of %c = %d",char_freq,flag);
	}
	if (flag==0)
	{
		printf("Frequency of %c = %d\n",char_freq,flag);
		printf("The character is not exist in the string");
	}
}