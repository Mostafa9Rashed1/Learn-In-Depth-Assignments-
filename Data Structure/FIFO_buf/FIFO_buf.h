
#ifndef FIFO_BUF_H_
#define FIFO_BUF_H_
#include "STD_TYPES.h"
#include <stdio.h>

// select element type (u8,u16,u32,........)
#define ELEMENT_TYPE	u8 


typedef struct {
	u32 length;
	u32 count;
	ELEMENT_TYPE* head;
	ELEMENT_TYPE* tail;
	ELEMENT_TYPE* base;  
	}FIFO_buf_t;
	
typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_Null
	}FIFO_status;

FIFO_status FIFO_init(FIFO_buf_t* ptr_fifo,ELEMENT_TYPE* buf,u32 length);	
FIFO_status FIFO_Add_item(FIFO_buf_t* ptr_fifo,s8 item);
FIFO_status FIFO_pop_item(FIFO_buf_t* ptr_fifo,ELEMENT_TYPE* item);
FIFO_status FIFO_IS_Buf_Full(FIFO_buf_t* ptr_fifo);
void FIFO_print(FIFO_buf_t* ptr_fifo);

#endif