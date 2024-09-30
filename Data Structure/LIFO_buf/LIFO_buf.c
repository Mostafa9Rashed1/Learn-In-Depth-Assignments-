#include "STD_TYPES.h"
#include "LIFO_buf.h"

#define Null 0

LIFO_BUl_Status LIFO_Add_item(LIFO_buf_t* ptr_lBuf,u8 item)
{
	// check LIFO is valid
	if (!ptr_lBuf->head || !ptr_lBuf->base)
		return LIFO_Null
	// check LIFO is full
	if (ptr_lBuf->count >= ptr_lBuf->length)
		return LIFO_full;
	
	// Add a new item
	*ptr_lBuf->head=item;
	ptr_lBuf->head++;
	ptr_lBuf->count++;

	return LIFO_no_error;
}

LIFO_BUl_Status LIFO_get_item(LIFO_buf_t* ptr_lBuf,u8* item)
{
	// check LIFO is valid
	if (!ptr_lBuf->head || !ptr_lBuf->base)
	return LIFO_Null
	// check LIFO is empty
	if (ptr_lBuf->count ==0 )
		return LIFO_empty;
	
	ptr_lBuf->head--;
	*item=*ptr_lBuf->head;
	ptr_lBuf->count--;
	
	return LIFO_no_error;
}
LIFO_BUl_Status LIFO_init(LIFO_buf_t* ptr_lBuf, s32* buf,u8 size)
{
	if(buf == Null)
		return LIFO_Null;
		
	ptr_lBuf->base=buf;
	ptr_lBuf->head=buf;
	ptr_lBuf->length=size;
	ptr_lBuf->count=0;
	
	return LIFO_no_error;
}