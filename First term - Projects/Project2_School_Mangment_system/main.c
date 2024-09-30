
#include "school_mangament_sys.h"

int main(void)
{
	FIFO_buf_t control_Buffer;
	Student_data buffer[100];	
	u8 choice;	
	// Initialize FIFO
	if (fifo_init(&control_Buffer, buffer, 100) == FIFO_no_error) 
		printf("FIFO Length: %d\n", control_Buffer.length); // Check length after initialization
			
	printf("\n\n\t\t******** SCHOOL MANAGEMENT SYSTEM *****\n\n");
	do {
		MAIN_MENU();
		printf("\t\tEnter your choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case 1: Add_Student(&control_Buffer);
			break;
			
			case 2: add_student_from_file(&control_Buffer);
			break;
			
			case 3:delete_Student(&control_Buffer);
			break;
			
			case 4:Student_List(&control_Buffer);
			break;
			
			case 5:Find_student_by_roll_number(&control_Buffer);
			break;
			
			case 6:Find_student_by_first_name(&control_Buffer);
			break;
			
			case 7:find_students_regist_in_course(&control_Buffer);
			break;
			
			case 8:Number_of_student(&control_Buffer);
			break;
						
			case 9:update_student(&control_Buffer);
			break;
			default:printf("\t\tInvalid choice! Please try again.\n");break;
		}
		
	} while (choice != 0);
	
	return 0;	
}