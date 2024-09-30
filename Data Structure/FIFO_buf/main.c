
#include "FIFO_buf.h"
#include <stdlib.h>

#define length_buf	5	

int main()
{
	FIFO_buf_t Buffer1;
	s8 str,item,char_condition;
	ELEMENT_TYPE element;
	u32 size,i=0;
	//printf("Enter number of element: ");
	//scanf("%d",&size);
	ELEMENT_TYPE* ptr_fifo= (ELEMENT_TYPE*)malloc(length_buf*sizeof(ELEMENT_TYPE));
	
	if (FIFO_init(&Buffer1 ,ptr_fifo , length_buf)== FIFO_no_error)
		printf("-----FIFO initialize is done-----\n");
	
	
	/*while (char_condition != 's' && i < length_buf )
	{
		printf("\nEnter the element to FIFO: ");
		scanf("%d",&item);
		FIFO_Add_item (&Buffer1,item);
		i++;
		printf("to continue enter any character and to stop Enter 's': ");
		scanf("%s",&char_condition);
	}*/
	
	
	FIFO_Add_item (&Buffer1,1);
	FIFO_Add_item (&Buffer1,2);
	FIFO_Add_item (&Buffer1,3);
	FIFO_Add_item (&Buffer1,4);
	FIFO_Add_item (&Buffer1,5);
	FIFO_Add_item (&Buffer1,6);
	FIFO_Add_item (&Buffer1,7);
	FIFO_print(&Buffer1);
	
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
	
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
	
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
	
	FIFO_Add_item (&Buffer1,11);
	FIFO_Add_item (&Buffer1,12);
	
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
		FIFO_print(&Buffer1);
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
	
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
		
		FIFO_print(&Buffer1);
		
	FIFO_pop_item(&Buffer1,&element);
	printf("FIFO pop an item: %d\n",element);
	
	free(ptr_fifo);
	
	return 0;  
}