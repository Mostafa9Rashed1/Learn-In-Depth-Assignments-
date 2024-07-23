#include <stdio.h>
#include "string.h"
#define  FRIST_CHAR 'A'
void main()
{
	char str[100],rvs_str[100];
	char *ptr=NULL;
	char *rvs_ptr=NULL;
	printf("Input a string : ");
	gets(str);
	int L=strlen(str);
	ptr=str;
	rvs_ptr=rvs_str;
	if (ptr !=NULL)
	{	
		for (int i=0;i<L;i++)
		{
			*ptr;
			ptr++;
		}
		for (int i=0;i<L;i++)
		{
			ptr--;
			*rvs_ptr=*ptr;
			rvs_ptr++;
		}
		
		printf("Reverse of the string is : %s",rvs_str);
		
	}
	else
	{
		printf("ERROR!!! NULL pointer");
	}
}