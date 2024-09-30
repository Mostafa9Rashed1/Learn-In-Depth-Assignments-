
// Single Linked List

#ifndef	LINLED_LIST_H_
#define LINLED_LIST_H_

#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
	u8 days;
	u8 months;
	u32 years;
}DOB;


typedef struct{
	s8 Name[30]  ;
	DOB  DOB_Student ;
	s8  Address[15];
	s32 ID;
	s8 Phone_Number[15];
	f32	height;
	f32 Student_Score;
}Student_Data;


typedef struct Node{
	Student_Data Data_Students;
	struct Node *NextPtr;
}Node_t;

typedef struct{
	u8 size;
	Node_t *HeadPtr;
}List_t;


void MAIN_MENU(void);
void New_Student(void);
void Delete_Student(void);
void studentList(void);
void STUDENT_EDIT(void);
void RANK_STUDENT(void) ;
void STUDENT_SCORE(void) ;
void Delete_All_Students(List_t* ListPtr);

List_t *Create_List(void);
void App_start(void);
void Add_Node(List_t* ListPtr,Student_Data Students_d);
void Delete_Node(List_t* ListPtr,Node_t* NodePtr);
void GetNth(List_t* ListPtr);
void number_of_Node();
void middle_List();
void Start(void);
void Exit(void);
extern List_t* List1;
#endif