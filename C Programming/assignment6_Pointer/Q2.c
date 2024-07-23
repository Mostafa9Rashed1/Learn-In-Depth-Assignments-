#include <stdio.h>
#define  FRIST_CHAR 'A'
void main()
{
	char alpha[27];
	char *ptr=NULL;
	ptr=alpha;
	if (ptr !=NULL)
	{
		
		for (int i=0;i<26;i++)
		{
			ptr[i]=FRIST_CHAR+i;
		}
		
		for (int i=0;i<26;i++)
		{
			printf("%c  ",ptr[i]);
		}
	} 
	else
	{
		printf("ERROR!!! NULL pointer");
	}
		
	
}