
#include "school_mangament_sys.h"

Student_data buffer[100];
 

void MAIN_MENU(void)
{
	
	DPRINTF("\n\t\t1. Add New Student Manually\n");
	DPRINTF("\t\t2. Add New Student from file\n");
	DPRINTF("\t\t3. Delete Student\n");
	DPRINTF("\t\t4. Student List\n");
	DPRINTF("\t\t5. Find a student by Roll number\n");
	DPRINTF("\t\t6. Find a student by First Name\n");
	DPRINTF("\t\t7. Find the students who register in one course\n");
	DPRINTF("\t\t8. Find the number of total students \n");
	DPRINTF("\t\t9. Edit th data of the student \n");
	DPRINTF("\t\t0. Exit\n\n");
}

FIFO_status shift_buffer(u32 index, FIFO_buf_t* fifoPtr) {
	if (!fifoPtr || !fifoPtr->base) {
		return FIFO_Null; // Check if FIFO exists
	}

	Student_data* current_student = fifoPtr->base;

	// Shift elements to the left, starting from the index
	for (u32 i = index; i < fifoPtr->count - 1; i++) {
		current_student[i] = current_student[i + 1];
	}
	
	// Clear the last element (optional)
	memset(&current_student[fifoPtr->count - 1], 0, sizeof(Student_data));

	printf("----------------------------------------------------------\n");
	printf("\t\tStudent deleted successfully\n");
	printf("----------------------------------------------------------\n");
	return FIFO_no_error;
}


FIFO_status fifo_init(FIFO_buf_t* fifoPtr, Student_data* buf, u32 length) {
	if (!fifoPtr || !buf ) 
	{
		return FIFO_Null; // Added check for zero length
	}
	
	fifoPtr->base = buf; // Initialize base
	fifoPtr->tail = buf; // Initialize tail
	fifoPtr->head = buf; // Initialize head
	fifoPtr->count = 0;  // Initialize count
	fifoPtr->length = length; // Set buffer length
	
	DPRINTF("[INFO] FIFO initialized with length: %d\n", fifoPtr->length);
	
	return FIFO_no_error;
}
	

u8 Check_Roll(FIFO_buf_t* fifoPtr,u16 check_roll)
{
	int i;
	Student_data* Local_Check_ptr = fifoPtr->base;
	
	for (i=0; i<(fifoPtr->count); i++ )
	{
		if (Local_Check_ptr->roll == check_roll )
		{
			return 0;
		}
		Local_Check_ptr++;
	}
	return 1; 
}	


FIFO_status Add_Student(FIFO_buf_t* fifoPtr)
{
	u16 temp_int;
	char temp_str[30];

	if (!fifoPtr->base || !fifoPtr->head) {
		DPRINTF("[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}
	// Check if FIFO is full
	if (fifoPtr->count == fifoPtr->length) {
		DPRINTF("[ERROR] FIFO is full! Cannot add more students.\n");
		return FIFO_full;
	}
	DPRINTF("----------------------------------------------------------\n");
	DPRINTF("\t\tAdd Student Details \n");
	DPRINTF("----------------------------------------------------------\n");

	// Enter Roll Number
	DPRINTF("\t\tEnter the Roll Number: ");
	gets(temp_str);
	temp_int = atoi(temp_str);

	// Check if roll number is already taken
	if (Check_Roll(fifoPtr, temp_int) == 0) {
		DPRINTF("[ERROR] Roll Number is already taken.\n");
		return FIFO_no_error; // Exit if roll number is taken
	}

	// Add details to the current student
	fifoPtr->head->roll = temp_int;

	DPRINTF("\t\tEnter First name of the student: ");
	gets(fifoPtr->head->first_name);

	DPRINTF("\t\tEnter Last name of the student: ");
	gets(fifoPtr->head->last_name);

	DPRINTF("\t\tEnter the GPA you obtained: ");
	gets(temp_str);
	fifoPtr->head->GPA = atof(temp_str); // Use atof for floating-point conversion
	while (fifoPtr->head->GPA <0 || fifoPtr->head->GPA >5)
	{
		printf("\n\t\tThe GPA is abnormal \n");
		printf("\t\tEnter Student GPA between 0 to 5: ");
		scanf("%f", &fifoPtr->head->GPA);
	}
	

	DPRINTF("\t\tEnter the course IDs of each course: \n");
	u16 course_ids[5] = {0}; // Array to store entered course IDs
	for (u16 i = 0; i < 5; i++) {
		while (1) {
			DPRINTF("\t\tCourse %d ID: ", i + 1);
			gets(temp_str);
			u16 course_id = atoi(temp_str);

			// Check for valid course ID
			if (course_id > 0 && course_id < 30) {
				// Check if the course ID has already been entered
				int already_exists = 0;
				for (u16 j = 0; j < i; j++) {
					if (course_ids[j] == course_id) {
						already_exists = 1;
						break;
					}
				}

				if (already_exists) {
					DPRINTF("[ERROR] Course ID %d has already been entered. Please enter a different ID.\n", course_id);
					} else {
					// Store the valid course ID
					course_ids[i] = course_id;
					fifoPtr->head->course_id[i] = course_id;
					break; // Exit the loop for successful entry
				}
				} else {
				DPRINTF("[ERROR] Course ID is not correct. Please enter a valid ID between 1 and 29.\n");
			}
		}
	}

	DPRINTF("\nStudent First Name: %s\n", fifoPtr->head->first_name);

	// Increment the head pointer and count after confirming the addition
	fifoPtr->head++;
	fifoPtr->count++;
	DPRINTF("[INFO] Student Details are added successfully.\n");
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[INFO] The total number of students is: %d\n", fifoPtr->count);
	DPRINTF("[INFO] You can add up to %d students.\n", fifoPtr->length);
	DPRINTF("[INFO] You can add more about %d students.\n", fifoPtr->length - fifoPtr->count);
	DPRINTF("-----------------------------------------------------------------\n");
	return FIFO_no_error;
}

FIFO_status Student_List(FIFO_buf_t* fifoPtr) 
{
	u8 x, y;
	Student_data* current_student = fifoPtr->base;
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}

	DPRINTF("---------------------------------------------------------------------\n");
	DPRINTF("\t\tStudent List\n");
	DPRINTF("---------------------------------------------------------------------\n");

	// Iterate through the student data
	for (x = 0; x < fifoPtr->count; x++) { // Show students data
		DPRINTF("----------------------------------------------------------\n");
		DPRINTF("Student Roll Number: %d\n", current_student->roll);
		DPRINTF("Student First Name: %s\n", current_student->first_name);
		DPRINTF("Student Last Name : %s\n", current_student->last_name);
		DPRINTF("Student GPA: %.2f\n", current_student->GPA);
		for (y = 0; y < 5; y++) 
		{
			DPRINTF("Course %d ID: %d\n", y + 1, current_student->course_id[y]);
		}
		current_student++;
	}

	DPRINTF("---------------------------------------------------------------------\n");
	DPRINTF("\tTotal Number of Students: %d\n", fifoPtr->count);
	return FIFO_no_error;
}


FIFO_status Find_student_by_roll_number(FIFO_buf_t* fifoPtr)
{
	u16 Vroll_find;
	u16 i;
	Student_data* current_Student =fifoPtr->base;
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}
	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}
	
	DPRINTF("\t\tEnter student Roll number: ");
	scanf("%d",&Vroll_find);
	i = 0;
	while (i < fifoPtr->count)
	{
		if (current_Student->roll == Vroll_find)
		{
			DPRINTF("\n---------------------------------------------------------------------------\n");
			DPRINTF("\t Student Roll Number: %d\n",current_Student->roll);
			DPRINTF("\t Student First Name : %s\n",current_Student->first_name);
			DPRINTF("\t Student Last Name  : %s\n",current_Student->last_name);
			DPRINTF("\t Student GPA  : %.2f\n",current_Student->GPA);
			for (u8 j=0; j<5; j++)
			{
				DPRINTF("\t course %d id : %d\n",j+1,current_Student->course_id[j]);
				
			}
			return FIFO_no_error;
		} 
		i++;
		current_Student++;
	}
	DPRINTF("\n---------------------------------------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");
	DPRINTF("\n---------------------------------------------------------------------------\n");
	return FIFO_error;
}

FIFO_status Find_student_by_first_name(FIFO_buf_t* fifoPtr)
{
	u8 Vfirst_name_find[20];
	u16 i;
	Student_data* current_Student =fifoPtr->base;
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}
	
	DPRINTF("\t\tEnter student First Name: ");
	gets(Vfirst_name_find);
	i = 0;
	while (i < fifoPtr->count)
	{
		if (strcmp(Vfirst_name_find,current_Student->first_name)==0)
		{
			DPRINTF("\n---------------------------------------------------------------------------\n");
			DPRINTF("\t Student Roll Number: %d\n",current_Student->roll);
			DPRINTF("\t Student First Name : %s\n",current_Student->first_name);
			DPRINTF("\t Student Last Name  : %s\n",current_Student->last_name);
			DPRINTF("\t Student GPA  : %.2f\n",current_Student->GPA);
			for (u8 j=0; j<5; j++)
			{
				DPRINTF("\t course %d id : %d\n",j+1,current_Student->course_id[j]);
				
			}
			return FIFO_no_error;
		}
		i++;
		current_Student++;
	}
	
	DPRINTF("\n---------------------------------------------------------------------------\n");
	DPRINTF("[ERROR] First Name is not found in the FIFO\n");
	DPRINTF("\n---------------------------------------------------------------------------\n");
	return FIFO_error;
}

FIFO_status find_students_regist_in_course(FIFO_buf_t* fifoPtr)
{
	u8 temp_str[20];
	u8 Vcourse_id_find;	u16 i,j,flag=0;
	Student_data* current_Student =fifoPtr->base;
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("\t [ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}
	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}
	DPRINTF("\t Enter ID course : ");
	gets(temp_str);
	Vcourse_id_find =atoi(temp_str);
	DPRINTF("---------------------------------------------------------------------------\n");
	for (i=0; i<fifoPtr->count; i++)
	{
		for (j=0; j<5; j++)
		{	
			if (current_Student->course_id[j] == Vcourse_id_find)
			{
				DPRINTF(" Student number %d\n",flag+1)
				DPRINTF("\t Student Roll Number: %d\n",current_Student->roll);
				DPRINTF("\t Student First Name : %s\n",current_Student->first_name);
				DPRINTF("\t Student Last Name  : %s\n",current_Student->last_name);
				DPRINTF("---------------------------------------------------------------------------\n");
				flag++;
			}
		}
		current_Student++;
	}
	DPRINTF("---------------------------------------------------------------------------\n");
	DPRINTF("Number of Student who registered in course %d id : %d ",Vcourse_id_find,flag);
	DPRINTF("\n---------------------------------------------------------------------------\n");
	if (flag == 0)
	{
		DPRINTF("\n---------------------------------------------------------------------------\n");
		DPRINTF("[ERROR] NO students registered in this Course\n");
		DPRINTF("\n---------------------------------------------------------------------------\n");
		return FIFO_error;
	}
	return FIFO_no_error;
}
	
FIFO_status Number_of_student(FIFO_buf_t* fifoPtr)
{
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("\t [ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}
	
	DPRINTF("---------------------------------------------------------------------------\n");
	DPRINTF("[INFO] The total number of students is: %d\n", fifoPtr->count);
	DPRINTF("[INFO] You can add up to %d students.\n", fifoPtr->length);
	DPRINTF("[INFO] You can add more about %d students.\n", fifoPtr->length - fifoPtr->count);
	DPRINTF("-----------------------------------------------------------------\n");
}	


/*FIFO_status delete_Student(FIFO_buf_t* fifoPtr)
{
	u8 index=0;
	u8 Vroll_delete;
	Student_data* current_student = fifoPtr->base;
	
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) { // Check if FIFO exists
		DPRINTF("\t [ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t [ERROR] Database is empty.\n");
		return FIFO_empty;
	}
	printf("Enter The roll number to be deleted : ");
	scanf("%d",&Vroll_delete);
	for (int i=0; i<fifoPtr->count; i++)
	{
		if (current_student->roll == Vroll_delete)
		{
			DPRINTF("---------------------------------------------------------------------------\n");
			shift_buffer(index,fifoPtr);
			fifoPtr->head--;
			fifoPtr->count--;
			return FIFO_no_error;
		} 
		else if (Vroll_delete == 0)
		{
			DPRINTF("---------------------------------------------------------------------------\n");
			DPRINTF("-------------------------Process cancled-----------------------------------\n");
			return FIFO_no_error;
		}
		else
		{
			DPRINTF("---------------------------------------------------------------------------\n");
			DPRINTF("[ERROR] wrong choice ..\n");
			return FIFO_no_error;
		}
		current_student++;
		index++;
	}
	
	DPRINTF("---------------------------------------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");
	DPRINTF("---------------------------------------------------------------------------\n");
	return FIFO_error;
}*/

FIFO_status delete_Student(FIFO_buf_t* fifoPtr) 
{
	u16 Vroll_delete;
	Student_data* current_student = fifoPtr->base;
	
	if (!fifoPtr || !fifoPtr->base) { // Check if FIFO exists
		printf("\t[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		printf("---------------------------------------------------------------------------\n");
		printf("\t[ERROR] Database is empty.\n");
		return FIFO_empty;
	}

	printf("Enter the roll number to be deleted: ");
	scanf("%d", &Vroll_delete);

	for (u32 i = 0; i < fifoPtr->count; i++) {
		if (current_student->roll == Vroll_delete) {
			printf("---------------------------------------------------------------------------\n");
			shift_buffer(i, fifoPtr);
			fifoPtr->count--;
			printf("[INFO] Student with roll number %d deleted successfully.\n", Vroll_delete);
			return FIFO_no_error;
		}
		current_student++;
	}

	printf("---------------------------------------------------------------------------\n");
	printf("[ERROR] Roll number %d not found.\n", Vroll_delete);
	return FIFO_error;
}

FIFO_status update_student(FIFO_buf_t* fifoPtr) {
	u16 Vroll_edit, choice;
	Student_data* current_student = fifoPtr->base;

	// Check if FIFO exists
	if (!fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) {
		DPRINTF("\t[ERROR] Data base does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is empty
	if (fifoPtr->count == 0) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t[ERROR] Database is empty.\n");
		return FIFO_empty;
	}

	DPRINTF("\n-------------------- Edit Student --------------------\n");
	DPRINTF("Enter the roll number to edit: ");
	scanf("%d", &Vroll_edit); 

	for (int i = 0; i < fifoPtr->count; i++) {
		if (current_student->roll == Vroll_edit) {
			DPRINTF("---------------------------------------------------------------------------\n");
			DPRINTF("\t1. Edit First name\n");
			DPRINTF("\t2. Edit Last name\n");
			DPRINTF("\t3. Edit GPA\n");
			DPRINTF("\t4. Edit course IDs\n");
			DPRINTF("---------------------------------------------------------------------------\n");
			DPRINTF("\tEnter your choice: ");
			scanf("%d", &choice); 

			switch (choice) {
				case 1:
				DPRINTF("\tEnter a New first name: ");
				gets(current_student->first_name);
				break;
				case 2:
				DPRINTF("\tEnter a New last name: ");
				gets(current_student->last_name);
				break;
				case 3:
				DPRINTF("\tEnter a New GPA: ");
				scanf("%f", &current_student->GPA); // Use %f for float
				while (current_student->GPA < 0 || current_student->GPA > 5) {
					DPRINTF("[ERROR] Invalid GPA. Enter a GPA between 0 and 5: ");
					scanf("%f", &current_student->GPA);
				}
				break;
				case 4:
				for (int j = 0; j < 5; j++) {
					DPRINTF("Enter a New course %d ID: ", j + 1);
					scanf("%d", &current_student->course_id[j]);
				}
				break;
				default:
				DPRINTF("[ERROR] Invalid choice. Please select a valid option.\n");
				return FIFO_error;
			}
			DPRINTF("[INFO] Student details updated successfully.\n");
			return FIFO_no_error;
		}
		current_student++; // Move to the next student
	}

	DPRINTF("---------------------------------------------------------------------------\n");
	DPRINTF("[ERROR] Roll number %d not found.\n", Vroll_edit);
	return FIFO_error;
}


FIFO_status add_student_from_file(FIFO_buf_t* fifoPtr) {
	u8 first_name[20], last_name[20];
	u16 roll_num;
	u8 course_ID[5], file_count = 0, line = 0;
	f32 GPA;

	// Check if FIFO exists
	if (!fifoPtr || !fifoPtr->head || !fifoPtr->base || !fifoPtr->tail) {
		DPRINTF("\t[ERROR] Database does not exist.\n");
		return FIFO_Null;
	}

	// Check if FIFO is full
	if (fifoPtr->count >= fifoPtr->length) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("\t[ERROR] FIFO is full.\n");
		return FIFO_full;
	}

	FILE *filePtr = fopen("text.txt", "r");
	if (!filePtr) {
		DPRINTF("---------------------------------------------------------------------------\n");
		DPRINTF("[ERROR] File not found.\n");
		return FIFO_error;
	}

	while (fscanf(filePtr, "%hu %19s %19s %f %hhu %hhu %hhu %hhu %hhu",
	&roll_num, first_name, last_name, &GPA,
	&course_ID[0], &course_ID[1], &course_ID[2], &course_ID[3], &course_ID[4]) == 9) {
		line++;

		// Check if FIFO is full
		if (fifoPtr->count >= fifoPtr->length) {
			DPRINTF("---------------------------------------------------------------------------\n");
			DPRINTF("[ERROR] Database is full.\n");
			DPRINTF("[INFO] Students added: %d\n", file_count);
			DPRINTF("[INFO] Remaining students due to size or error: %d\n", line - file_count);
			fclose(filePtr);
			return FIFO_full;
		}

		// Check for unique roll number
		if (Check_Roll(fifoPtr, roll_num) == 0) {
			DPRINTF("[ERROR] In line %d: Roll number %hu is already taken.\n", line, roll_num);
			continue;
		}

		// Assign student data
		fifoPtr->head->roll = roll_num;
		fifoPtr->head->GPA = GPA;
		strcpy(fifoPtr->head->first_name, first_name);
		strcpy(fifoPtr->head->last_name, last_name);

		// Validate course IDs
		int valid_courses = 1;
		for (int i = 0; i < 5; i++) {
			if (course_ID[i] < 0 || course_ID[i] > 30) {
				valid_courses = 0;
				break;
			}
			fifoPtr->head->course_id[i] = course_ID[i];
		}

		// Check for valid course IDs
		if (!valid_courses) {
			DPRINTF("[ERROR] In line %d: Invalid course ID(s). Skipping this student.\n", line);
			continue;
		}

		// Update FIFO
		fifoPtr->head++;
		fifoPtr->count++;
		file_count++;
	}

	DPRINTF("\nEnd of file.\n");
	fclose(filePtr);
	DPRINTF("[INFO] Students added: %d\n", file_count);
	DPRINTF("[INFO] Remaining students due to errors: %d\n", line - file_count);
	return FIFO_no_error;
}




/*FIFO_status Start(FIFO_buf_t *fifoPtr) {
	Student_data data;
	FILE *read_file = fopen("data.txt", "r");
	int line = 0, file_count = 0;

	if (read_file == NULL) {
		DPRINTF("[INFO] data.txt not found. Please enter student data manually.\n");
		while (file_count < fifoPtr->length) {
			printf("Enter first name, last name, roll number, GPA, and 5 course IDs (space-separated):\n");
			if (scanf("%s %s %hu %f %d %d %d %d %d",
			data.first_name,
			data.last_name,
			&data.roll,
			&data.GPA,
			&data.course_id[0],
			&data.course_id[1],
			&data.course_id[2],
			&data.course_id[3],
			&data.course_id[4]) != 9) {
				DPRINTF("[ERROR] Invalid input. Please try again.\n");
				continue;
			}

			line++;

			if (fifoPtr->count == fifoPtr->length) {
				DPRINTF("[ERROR] Database is full after entering %d lines.\n", line);
				return FIFO_full;
			}

			if (Check_Roll(fifoPtr, data.roll) == 0) {
				DPRINTF("[ERROR] Line %d: Roll Number %hu is already taken.\n", line, data.roll);
				continue;
			}

			int valid = 1;
			for (int x = 0; x < 5; x++) {
				if (data.course_id[x] < 0 || data.course_id[x] > 30) {
					DPRINTF("[ERROR] Line %d: Invalid course ID %d. Skipping student.\n", line, data.course_id[x]);
					valid = 0;
					break;
				}
				fifoPtr->head->course_id[x] = data.course_id[x];
			}

			if (valid) {
				fifoPtr->head->roll = data.roll;
				fifoPtr->head->GPA = data.GPA;
				strcpy(fifoPtr->head->first_name, data.first_name);
				strcpy(fifoPtr->head->last_name, data.last_name);

				fifoPtr->head++;
				fifoPtr->count++;
				file_count++;
			}
		}
		return FIFO_no_error;
	}

	while (fscanf(read_file, "%s %s %hu %f %d %d %d %d %d\n",
	data.first_name,
	data.last_name,
	&data.roll,
	&data.GPA,
	&data.course_id[0],
	&data.course_id[1],
	&data.course_id[2],
	&data.course_id[3],
	&data.course_id[4]) != EOF) {
		line++;

		if (fifoPtr->count == fifoPtr->length) {
			DPRINTF("[ERROR] Database is full after reading %d lines.\n", line);
			fclose(read_file);
			return FIFO_full;
		}

		if (Check_Roll(fifoPtr, data.roll) == 0) {
			DPRINTF("[ERROR] Line %d: Roll Number %hu is already taken.\n", line, data.roll);
			continue;
		}

		int valid = 1;
		for (int x = 0; x < 5; x++) {
			if (data.course_id[x] < 0 || data.course_id[x] > 30) {
				DPRINTF("[ERROR] Line %d: Invalid course ID %d. Skipping student.\n", line, data.course_id[x]);
				valid = 0;
				break;
			}
			fifoPtr->head->course_id[x] = data.course_id[x];
		}

		if (valid) {
			fifoPtr->head->roll = data.roll;
			fifoPtr->head->GPA = data.GPA;
			strcpy(fifoPtr->head->first_name, data.first_name);
			strcpy(fifoPtr->head->last_name, data.last_name);

			fifoPtr->head++;
			fifoPtr->count++;
			file_count++;
		}
	}

	fclose(read_file);
	DPRINTF("[INFO] Successfully loaded students: %d\n", file_count);
	DPRINTF("[INFO] Remaining students due to errors: %d\n", line - file_count);
	return FIFO_no_error;
}

FIFO_status Exit(FIFO_buf_t *fifoPtr) {
	FILE *final_data = fopen("data.txt", "w");
	FILE *spreadsheet = fopen("SpreadSheet.txt", "w");
	int i;

	if (final_data == NULL || spreadsheet == NULL) {
		DPRINTF("[ERROR] Unable to open output files.\n");
		return FIFO_error;
	}

	DPRINTF("[INFO] Saving data...\n");
	fprintf(spreadsheet, "\n----- Student List -----\n");
	fprintf(spreadsheet, "%-20s %-20s %-15s %-10s %-15s\n", "First Name", "Last Name", "Roll Number", "GPA", "Course IDs");

	for (i = 0; i < fifoPtr->count; i++) {
		Student_data *temp = &fifoPtr->base[i];

		fprintf(final_data, "%s\t%s\t%hu\t%.2f\t",
		temp->first_name, temp->last_name, temp->roll, temp->GPA);
		
		for (int j = 0; j < 5; j++) {
			fprintf(final_data, "%d ", temp->course_id[j]);
		}
		fprintf(final_data, "\n");

		fprintf(spreadsheet, "%-20s %-20s %-15hu %.2f ",
		temp->first_name, temp->last_name, temp->roll, temp->GPA);
		
		for (int j = 0; j < 5; j++) {
			fprintf(spreadsheet, "%d ", temp->course_id[j]);
		}
		fprintf(spreadsheet, "\n");
	}

	fclose(final_data);
	fclose(spreadsheet);
	DPRINTF("[INFO] Data saved successfully to files.\n");
	return FIFO_no_error;
}

*/