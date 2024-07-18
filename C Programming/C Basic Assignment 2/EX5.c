# include "stdio.h"

void main ()
{
	char ch ;
	printf("Enter a character: ");
	scanf("%c",&ch);
	if ((ch>64 && ch<91) || ch>96 && ch <123 )
	{
		printf("character is an Alphabet"); 
	}
	else
	{
		printf("character is not an Alphabet"); 
	}
	
}