


#ifndef LIFO_BUF_H_
#define LIFO_BUF_H_  

typedef struct {
	s32* base ;
	s32* head; 
	u32 length;
	u32 count;
	}LIFO_buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_Null
	}LIFO_BUl_Status; 

LIFO_BUl_Status LIFO_Add_item(LIFO_buf_t* ptr_lBuf,u8 item);
LIFO_BUl_Status LIFO_get_item(LIFO_buf_t* ptr_lBuf,u8* item);
LIFO_BUl_Status LIFO_init(LIFO_buf_t* ptr_lBuf, s32* buf,u8 size);


#endif