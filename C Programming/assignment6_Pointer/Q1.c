#include <stdio.h>

void main()
{
	int m=29;
	int *ab=NULL;
	ab=&m;
	printf("Address of m : 0x%x\n",&m);
	printf(" value of m : %d\n\n",m);
	printf("Now ab is assigned with the address of m\n");
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("content of pointer : %d\n\n",*ab);
	*ab=34;
	printf("The value of m assigned to %d now\n",m);
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("content of pointer : %d\n\n",*ab);
	
	*ab=7;
	printf("The pointer variable ab is assigned with the value %d now.\n",m);
	printf("Address of m : 0x%x\n",&m);
	printf(" value of m : %d\n\n",m);
}







