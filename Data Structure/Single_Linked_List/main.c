

#include "linked_list.h"

int main(void)
{
	
	App_start();


	Start();
	
	printf("\n\n\t\t******** SCHOOL MANAGEMENT SYSTEM *****\n\n");
	int choice;
	do {
		MAIN_MENU();
		printf("\t\tEnter your choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case 1: New_Student();
			break;
			
			case 2:Delete_Student();
			break;
			
			case 3:studentList();
			break;
			
			case 4:STUDENT_EDIT();
			break;
			
			case 5:RANK_STUDENT();
			break;
			
			case 6:STUDENT_SCORE();
			break;
			
			case 7:Delete_All_Students(List1);
			break;
			
			case 8:GetNth(List1);
			break;
			
			case 9:number_of_Node();
			break;
			
			case 10:middle_List();
			break;
			
			case 0:printf("\t\tExiting...\n");
			break;

			default:printf("\t\tInvalid choice! Please try again.\n");break;
		}
		
	} while (choice != 0);
		
	Exit();	
	
	return 0;
}