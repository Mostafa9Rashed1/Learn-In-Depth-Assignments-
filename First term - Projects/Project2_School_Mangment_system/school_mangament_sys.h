

#ifndef SCHOOL_MANAGAMENT_SYS_H_
#define SCHOOL_MANAGAMENT_SYS_H_ 

#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX_LENGTH	100

#define DPRINTF(...)		{fflush(stdin);\
							fflush(stdout);\
							printf(__VA_ARGS__);\
							fflush(stdin);\
							fflush(stdout);}					

										
typedef struct {
		u8 first_name[20];
		u8 last_name[20];
		u16 roll;
		float GPA;
		u8 course_id[10];
	}Student_data;
									



typedef struct {
	u32 length;
	u32 count;
	Student_data* head;
	Student_data* tail;
	Student_data* base;
}FIFO_buf_t;



typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_Null,
	FIFO_error
}FIFO_status;


FIFO_status fifo_init(FIFO_buf_t* fifoPtr,Student_data* buf,u32 length );
FIFO_status Add_Student(FIFO_buf_t* fifoPtr);
FIFO_status Student_List(FIFO_buf_t* fifoPtr);
FIFO_status Find_student_by_roll_number(FIFO_buf_t* fifoPtr);
FIFO_status Find_student_by_first_name(FIFO_buf_t* fifoPtr);
FIFO_status find_students_regist_in_course(FIFO_buf_t* fifoPtr);
FIFO_status Number_of_student(FIFO_buf_t* fifoPtr);
FIFO_status delete_Student(FIFO_buf_t* fifoPtr);
FIFO_status update_student(FIFO_buf_t* fifoPtr);
FIFO_status add_student_from_file(FIFO_buf_t* fifoPtr);

void MAIN_MENU(void);


u8 Check_Roll(FIFO_buf_t* fifoPtr,u16 check_roll);
FIFO_status shift_buffer(u32 index, FIFO_buf_t* fifoPtr);

extern Student_data buffer[100];

#endif
