#include "FIFO_buf.h"

FIFO_status FIFO_IS_Buf_Full(FIFO_buf_t* ptr_fifo)
{
	
	if (!ptr_fifo->base || !ptr_fifo->tail || !ptr_fifo->head)
		return FIFO_Null;
	
		if (ptr_fifo->length == ptr_fifo->count)
	{
		printf("FIFO is full !\n");
		return FIFO_full;
	}
	return FIFO_no_error;
}


FIFO_status FIFO_init(FIFO_buf_t* ptr_fifo,ELEMENT_TYPE* buf,u32 length)
{	
	ptr_fifo->count=0;	
	ptr_fifo->base=buf;
	ptr_fifo->head=buf;
	ptr_fifo->tail=buf;
	ptr_fifo->length=length;
	
	if (ptr_fifo->base && ptr_fifo->length)
		{
			
			return FIFO_no_error;
		}
		
	else	
		return FIFO_Null;
}


FIFO_status FIFO_Add_item(FIFO_buf_t* ptr_fifo,s8 item)
{
	if (FIFO_IS_Buf_Full(ptr_fifo) == FIFO_no_error)
	{
		*ptr_fifo->head=item;
		ptr_fifo->count++;	
		
		if (ptr_fifo->head == (ptr_fifo->base + ptr_fifo->length * sizeof(ELEMENT_TYPE)))
			ptr_fifo->head = ptr_fifo->base;
		else
			ptr_fifo->head++;
			
		return FIFO_no_error;
	} 
	else
	{
		printf("FIFO is failed \n");
		return (FIFO_IS_Buf_Full(ptr_fifo)); 
	}
		
}

FIFO_status FIFO_pop_item(FIFO_buf_t* ptr_fifo,ELEMENT_TYPE* item)
{
	if (!ptr_fifo->base || !ptr_fifo->tail || !ptr_fifo->head)
	return FIFO_Null;
	if (ptr_fifo->count == 0)
	{
		printf("FIFO is Empty\n");
		return	FIFO_empty;
	} 
	else
	{
		*item=*ptr_fifo->tail;
		ptr_fifo->count--;
		if (ptr_fifo->tail == (ptr_fifo->base + ptr_fifo->length * sizeof(ELEMENT_TYPE)))
			ptr_fifo->tail = ptr_fifo->base;
		else
		{
			ptr_fifo->tail++;
		}
		return FIFO_no_error;
	}
}


void FIFO_print(FIFO_buf_t* ptr_fifo)
{
	u8 i;
	ELEMENT_TYPE* ptr_print=NULL;
	if (ptr_fifo->count == 0)
	{
		printf("FIFO is empty");
	} 
	else
	{
		printf("\n-------FIFO Print-------\n");
		ptr_print=ptr_fifo->tail;
		for (i=0;i<ptr_fifo->count ;i++)
		{
			printf("\t %d\n",*ptr_print);
			ptr_print++;
		}
		
	}
}

