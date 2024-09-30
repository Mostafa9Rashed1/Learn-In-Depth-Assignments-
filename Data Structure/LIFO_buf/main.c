#include <stdio.h>
#include "STD_TYPES.h"
#include "LIFO_buf.h"
#include <stdlib.h>



int main()
{
	u8 size; 
	u8 temp;	

	LIFO_buf_t  Buffer1;
	printf("Enter number of items: ");
	scanf("%d",&size);
	s32* ptr_lifo= (s32*)malloc(size*sizeof(s32));
	LIFO_init(&Buffer1,ptr_lifo,size);	
	
	for (int i=0;i<size;i++)
	{
		if (LIFO_Add_item(&Buffer1,i)== LIFO_no_error)
			printf("LIFO Add a new item: %d\n",i);
	}
	
	for (int i=0;i<size;i++)
	{
		if (LIFO_get_item(&Buffer1,&temp) == LIFO_no_error)
		printf("LIFO pop an item: %d\n",temp);
		
	}
	
	free(ptr_lifo);
	
	return 0;
}