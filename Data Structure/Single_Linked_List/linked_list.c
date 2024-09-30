
// single Linked List

#include "linked_list.h"

List_t* List1;


List_t *Create_List(void)
{
	List_t*  LocalRtnPtr = NULL;
	List_t* ListPtr = (List_t*)malloc(sizeof(List_t));
	if (ListPtr != NULL)
	{
		ListPtr->size=0;
		ListPtr->HeadPtr=NULL; 
		LocalRtnPtr=ListPtr;
	} 
	else
	{
		printf("\t\tError: Pointer of List is Null\n");
	}
	return LocalRtnPtr;
	
}

void App_start(void)
{
	List1=Create_List();
}


void Add_Node(List_t* ListPtr, Student_Data Students_d) {
	Node_t *NewNodePtr = (Node_t *)malloc(sizeof(Node_t));
	if (NewNodePtr == NULL) {
		printf("\t\tError: Unable to allocate memory for new node.\n");
		return;
	}

	NewNodePtr->Data_Students = Students_d;
	NewNodePtr->NextPtr = NULL;  // Initialize the next pointer to NULL

	// Check if the list is empty
	if (ListPtr->HeadPtr == NULL) {
		ListPtr->HeadPtr = NewNodePtr;  // First node
		} else {
		Node_t *CurrentNode = ListPtr->HeadPtr;
		// Traverse to the end of the list
		while (CurrentNode->NextPtr != NULL) {
			CurrentNode = CurrentNode->NextPtr;
		}
		CurrentNode->NextPtr = NewNodePtr;  // Link the new node at the end
	}

	ListPtr->size++;  // Increment the size of the list
}


void Delete_Node(List_t* ListPtr, Node_t* NodePtr) {
	// Check if the list is empty
	if (ListPtr->HeadPtr == NULL || NodePtr == NULL) {
		printf("\t\tError: List is empty or node is NULL.\n");
		return;
	}

	Node_t *CurrentNode = ListPtr->HeadPtr;
	Node_t *PreviousNode = NULL;

	// Traverse the list to find the node to delete
	while (CurrentNode != NULL && CurrentNode != NodePtr) {
		PreviousNode = CurrentNode;
		CurrentNode = CurrentNode->NextPtr;
	}

	// Check if the node was not found
	if (CurrentNode == NULL) {
		printf("\t\tError: Node not found in the list.\n");
		return;
	}

	// If the node to delete is the head node
	if (CurrentNode == ListPtr->HeadPtr) {
		ListPtr->HeadPtr = CurrentNode->NextPtr;  // Update head to the next node
		} else {
		// Link the previous node to the next node
		PreviousNode->NextPtr = CurrentNode->NextPtr;
	}

	// Free the memory allocated for the node
	free(CurrentNode);
	ListPtr->size--;  // Decrement the size of the list
}




void MAIN_MENU(void)
{
		printf("\n\t\t1. Add New Student\n");
		printf("\t\t2.  Delete Student\n");
		printf("\t\t3.  Student List\n");
		printf("\t\t4.  Edit Student\n");
		printf("\t\t5.  Rank Students\n");
		printf("\t\t6.  Update Scores\n");
		printf("\t\t7.  Delete All students\n");
		printf("\t\t8.  Get student by index\n");
		printf("\t\t9.  Get Number of students\n");
		printf("\t\t10. Get Middle students in the List\n");
		printf("\t\t0.  Exit\n\n");
}


void New_Student(void)
{
	Student_Data Student_Str;

	printf("\t\tEnter the Name: ");
	scanf("%s", &Student_Str.Name);

	printf("\t\tEnter date of birth(DD/MM/YYYY): ");
	scanf("%d/%d/%d", &Student_Str.DOB_Student.days, &Student_Str.DOB_Student.months, &Student_Str.DOB_Student.years);
	
	while (Student_Str.DOB_Student.days <= 0 || Student_Str.DOB_Student.days > 31 || Student_Str.DOB_Student.months <= 0 || Student_Str.DOB_Student.months > 12 || Student_Str.DOB_Student.years >2005 || Student_Str.DOB_Student.years <1998 || (Student_Str.DOB_Student.months ==2 && Student_Str.DOB_Student.days > 29) )
	{
		printf("\n\t\tpls Enter date of birth correctly \n");
		printf("\t\tEnter date of birth(DD/MM/YYYY): ");
		scanf("%d/%d/%d", &Student_Str.DOB_Student.days, &Student_Str.DOB_Student.months, &Student_Str.DOB_Student.years);
	}
	
	while (1)
	{
		printf("\t\tEnter ID: ");
		scanf("%d", &Student_Str.ID);

		if (Student_Str.ID < 0)
		{
			
			printf("\t\tID cannot be negative. Please enter a valid ID.\n");
		}
		else
		{
			// Check if ID already exists
			Node_t* temp = List1->HeadPtr;
			while (temp != NULL)
			{
				if (temp->Data_Students.ID == Student_Str.ID)
				{
					printf("\t\tID already exists. Please enter a unique ID.\n");
					break;
				}
				temp = temp->NextPtr;
			}

			if (temp == NULL)
			{
				break; // ID is valid and unique
			}
		}
	}
	printf("\t\tEnter Address: ");
	scanf("%s", &Student_Str.Address);

	printf("\t\tEnter Phone Number: ");
	scanf("%s", &Student_Str.Phone_Number);
	
	printf("\t\tEnter Student Score: ");
	scanf("%f", &Student_Str.Student_Score);
	
	while (Student_Str.Student_Score < 0 || Student_Str.Student_Score > 100)
	{
		printf("\n\t\tThe score is abnormal \n");
		printf("\t\tEnter Student Score between 0 to 100: ");
		scanf("%f", &Student_Str.Student_Score);
	}
	
	printf("\t\tEnter Student Height: ");
	scanf("%f", &Student_Str.height);
	
	printf("\t\tStudent added successfully!\n");

	Add_Node(List1, Student_Str);
}

void Delete_Student(void)
{
	u8 id,flag=0;
	printf("\t\t----- Delete Student -----\n");
	printf("\t\tEnter ID of the student to be deleted: ");
	scanf("%d", &id);
	
	Node_t *del_Node=List1->HeadPtr;
	printf("\n\t\n%d\n",del_Node->Data_Students.ID);
	
	while(del_Node !=NULL && flag !=1)
	{
		flag=0;
		if (del_Node->Data_Students.ID==id )
		{
			Delete_Node(List1,del_Node);
			flag=1;
		}
		del_Node=del_Node->NextPtr;
	}

	if (flag ==1)
	{
		printf("\t\tStudent with ID %d deleted successfully!\n", id);
	}
	else if (flag==0)
	{
		printf("\t\tStudent with ID %d deletion failed !!\n", id);
	}
	else
	{
		printf("\t\tError 303");
	}
	
}

void studentList(void)
{
	printf("\n\t------- Student List -------\n");
	if (List1->HeadPtr == NULL) 
	{
		printf("\t\tNo students found!\n");
		return;
	}
	
	// Create a temporary array to store names
	u8 count = List1->size;
	u8** names = (u8**)malloc(count * sizeof(u8*));
	if (names == NULL) 
	{
		printf("\t\tMemory allocation failed!\n");
		return;
	}

	// Copy names into the temporary array
	Node_t* tempPtr = List1->HeadPtr;
	u8 i = 0;
	while (tempPtr != NULL && i < count) 
	{
		names[i] = tempPtr->Data_Students.Name;
		tempPtr = tempPtr->NextPtr;
		i++;
	}
	
	// Sort the names array in alphabetical ascending order 
	u8 j,k;
	u8* tempName;
	for ( j = 0; j < count - 1; j++) 
	{
		for ( k = j + 1; k < count; k++) 
		{
			if (strcmp(names[j], names[k]) > 0) 
			{
				tempName = names[j];
				names[j] = names[k];
				names[k] = tempName;
			}
		}
	}
	s8* Id_prev;
	u8 c1,flag;
	Id_prev=malloc(sizeof(s8));
	u8 Len=0;
	Id_prev[0]=-1;
	// Print the sorted student details
	printf("\t\t%-20s %-5s %-15s %-15s %-15s%-15s%-8s\n", "Name", "ID", "Date of Birth", "Address", "Phone", "Score","Height");
	for ( j = 0; j < count; j++) 
	{
		tempPtr = List1->HeadPtr;
		while (tempPtr != NULL) 
		{
			if (strcmp(tempPtr->Data_Students.Name, names[j])  == 0)			 
			{
					flag=1;
					for (c1=0;c1<=Len;c1++)
					{
						if (Id_prev[c1]==tempPtr->Data_Students.ID)
						{
							flag=0;
							break;
						}
						
					}
					if(flag ==1)
					{
						printf("\t\t%-20s %-5d %d/%d/%-9d  %-15s %-15s%.2f           %.2f\n", tempPtr->Data_Students.Name, tempPtr->Data_Students.ID, tempPtr->Data_Students.DOB_Student.days, tempPtr->Data_Students.DOB_Student.months, tempPtr->Data_Students.DOB_Student.years, tempPtr->Data_Students.Address, tempPtr->Data_Students.Phone_Number, tempPtr->Data_Students.Student_Score,tempPtr->Data_Students.height);
						Len++;
						realloc(Id_prev,(sizeof(s8)*(Len+1)));  //using realloc to redfine the array to change its size
						Id_prev[Len]=tempPtr->Data_Students.ID;
						break;
					}
													
			}
			tempPtr = tempPtr->NextPtr;
		}
	}

	free(names); // Free the temporary array
	free(Id_prev);
}


void STUDENT_EDIT(void) {
	int id, flag = 0;
	printf("\n\t----- Edit Student -----\n");
	printf("\t\tEnter ID of the student to edit: ");
	scanf("%d", &id);

	Node_t* editNode = List1->HeadPtr;

	while (editNode != NULL)
	{
		if (editNode->Data_Students.ID == id)
		{
			flag = 1;
			break;
		}
		editNode = editNode->NextPtr;
	}

	if (flag == 0) {
		printf("\t\tStudent with ID %d not found!\n", id);
		return;
	}

	printf("\t\t1. Edit name\n");
	printf("\t\t2. Edit date of birth\n");
	printf("\t\t3. Edit address\n");
	printf("\t\t4. Edit phone\n");
	printf("\t\tEnter your choice: ");
	int choice;
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		printf("\t\tEnter new name: ");
		scanf("%s", editNode->Data_Students.Name);
		break;
		case 2:
		printf("\t\tEnter new date of birth: ");
		scanf("%d/%d/%d", &editNode->Data_Students.DOB_Student.days,&editNode->Data_Students.DOB_Student.months,&editNode->Data_Students.DOB_Student.years);
		while (editNode->Data_Students.DOB_Student.days <= 0 || editNode->Data_Students.DOB_Student.days > 31 || editNode->Data_Students.DOB_Student.months <= 0 || editNode->Data_Students.DOB_Student.months > 12 || editNode->Data_Students.DOB_Student.years >2005 || editNode->Data_Students.DOB_Student.years <1998 )
		{
			printf("\n\t\tpls Enter date of birth correctly \n");
			printf("\t\tEnter date of birth(DD/MM/YYYY): ");
			scanf("%d/%d/%d", &editNode->Data_Students.DOB_Student.days, &editNode->Data_Students.DOB_Student.months, &editNode->Data_Students.DOB_Student.years);
		}
		break;
		case 3:
		printf("\t\tEnter new address: ");
		scanf("%s", editNode->Data_Students.Address);
		break;
		case 4:
		printf("\t\tEnter new phone number: ");
		scanf("%s", &editNode->Data_Students.Phone_Number);
		break;
		default:
		printf("\t\tInvalid choice\n");
	}

	printf("\t\tStudent with ID %d updated!\n", id);
}

void RANK_STUDENT(void)
{
	Node_t *current, *next;
	Student_Data tempStr;
	// Bubble sorting
	for(current = List1->HeadPtr; current != NULL; current = current->NextPtr)
	{
		for(next = current->NextPtr; next != NULL; next = next->NextPtr)
		{
			if(current->Data_Students.Student_Score < next->Data_Students.Student_Score)
			{
				// Swap students
				tempStr = current->Data_Students;
				current->Data_Students = next->Data_Students;
				next->Data_Students = tempStr;
			}
		}
	}
	

	// Print ranked list
	current = List1->HeadPtr;
	int rank = 1;
	printf("\n\t\tRank\tID\tName\t\tScore\n");
	
	while(current != NULL)
	{
		printf("\t\t%d\t%d\t%s\t\t%.2f\n", rank,current->Data_Students.ID ,current->Data_Students.Name, current->Data_Students.Student_Score);
		current = current->NextPtr;
		rank++;
	}
}

void STUDENT_SCORE(void)
{
	u8 id;
	f32 new_Score;
	printf("\t\tEnter ID of student to update score: ");
	scanf("%d", &id);

	Node_t *updateNode = List1->HeadPtr;

	while(updateNode != NULL)
	{
		if(updateNode->Data_Students.ID == id)
		{
			printf("\t\tEnter new score: ");
			scanf("%f", &new_Score);
			while (new_Score < 0 || new_Score > 100)
			{
				printf("\n\t\tThe score is abnormal \n");
				printf("\t\tEnter new score between 0 to 100: ");
				scanf("%f", &new_Score);
				
			}
			updateNode->Data_Students.Student_Score = new_Score;
			printf("\t\tScore updated successfully!\n");
			return;
		}
		updateNode = updateNode->NextPtr;
	}
	printf("\t\tStudent with ID %d not found!\n", id);
}


void Delete_All_Students(List_t* ListPtr) {
	// Check if the list is empty
	if (ListPtr->HeadPtr == NULL) {
		printf("\t\tError: List is already empty.\n");
		return;
	}

	Node_t* CurrentNode = ListPtr->HeadPtr;
	Node_t* NextNode;

	// Traverse the list and free each node
	while (CurrentNode != NULL) {
		NextNode = CurrentNode->NextPtr;  // Store the next node
		free(CurrentNode);                 // Free the current node
		CurrentNode = NextNode;            // Move to the next node
	}

	// Set the head pointer to NULL and size to 0
	ListPtr->HeadPtr = NULL;
	ListPtr->size = 0;

	printf("\t\tAll students deleted successfully!\n");
}



void Exit(void)
{
	FILE *final_data;
	FILE *SpreadSheet;
	remove("data.txt");
	remove("SpreadSheet.txt");
	final_data=fopen("data.txt","w");
	SpreadSheet=fopen("SpreadSheet.txt","w");
	fprintf(SpreadSheet,"\n----- Student List -----\n");
	if (List1->HeadPtr == NULL)
	{
		return;
	}
	
	Node_t* temp = List1->HeadPtr;
	fprintf(SpreadSheet,"%-20s %-5s %-15s %-15s %-15s%-15s\n", "Name", "ID", "Date of Birth", "Address", "Phone", "Score");
	while (temp != NULL) {
		fprintf(final_data,"%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t%f\n", temp->Data_Students.Name,temp->Data_Students.ID, temp->Data_Students.DOB_Student.days,  temp->Data_Students.DOB_Student.months, temp->Data_Students.DOB_Student.years ,temp->Data_Students.Address, temp->Data_Students.Phone_Number,temp->Data_Students.Student_Score);
		fprintf(SpreadSheet,"%-20s %-5d %d/%d/%-9d  %-15s %-15s%.2f\n", temp->Data_Students.Name,temp->Data_Students.ID, temp->Data_Students.DOB_Student.days,  temp->Data_Students.DOB_Student.months, temp->Data_Students.DOB_Student.years ,temp->Data_Students.Address, temp->Data_Students.Phone_Number,temp->Data_Students.Student_Score);
		temp = temp->NextPtr;
		
	}
}

void Start(void)
{
	Student_Data data;

	FILE *read_file=fopen("data.txt","r");

	if (read_file==NULL)
	{
		printf("No file\n");
		return;
	}
	//"", temp->Data_Students.Name_frist,temp->Data_Students.ID, temp->Data_Students.DOB_Student.days,  temp->Data_Students.DOB_Student.months, temp->Data_Students.DOB_Student.years ,temp->Data_Students.Address, temp->Data_Students.Phone_Number,temp->Data_Students.Student_Score);
	while(fscanf(read_file,"%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t%f\n", &data.Name, &data.ID, &data.DOB_Student.days,&data.DOB_Student.months,&data.DOB_Student.years, &data.Address, &data.Phone_Number,&data.Student_Score)!=EOF)
	{
		Add_Node(List1,data);
	}
	fclose(read_file);
}


void GetNth(List_t* ListPtr) {
	// Initialize current node and count
	u8 index;

	Node_t* tempPtr = ListPtr->HeadPtr;
	int count = 0;
	printf("\t\tEnter the index of student:  ");
	scanf("%d",&index);
	// Validate index
	if (index < 0) {
		printf("\t\tError: Index cannot be negative.\n");
		// Return a default or error value as needed
		Student_Data emptyData = {0}; // Assuming Student_Data has a way to represent an empty state
	}
	if (ListPtr->size <= index)
	{
		// If we reach here, index is out of bounds
		printf("\t\tError: Index %d is out of bounds.\n", index);
		Student_Data emptyData = {0}; // Assuming Student_Data has a way to represent an empty state
		
	}

	// Traverse the list
	while (tempPtr != NULL) {
		if (count == index) {
			printf("\n\t\t%-20s %-5s %-15s %-15s %-15s%-15s%-8s\n", "Name", "ID", "Date of Birth", "Address", "Phone", "Score","Height");
			printf("\t\t%-20s %-5d %d/%d/%-9d  %-15s %-15s%.2f           %.2f\n", tempPtr->Data_Students.Name, tempPtr->Data_Students.ID, tempPtr->Data_Students.DOB_Student.days, tempPtr->Data_Students.DOB_Student.months, tempPtr->Data_Students.DOB_Student.years, tempPtr->Data_Students.Address, tempPtr->Data_Students.Phone_Number, tempPtr->Data_Students.Student_Score,tempPtr->Data_Students.height);		
		}
		count++;
		tempPtr = tempPtr->NextPtr; // Move to the next node
	}
	
	
	
}


void number_of_Node()
{
	u8 count=0;
	List_t* ListPtr= List1;
	Node_t* countPtr= ListPtr->HeadPtr;
	if (ListPtr->HeadPtr == NULL)
	{
		printf("\n\t\t List is empty");
	} 
	else
	{
		do 
		{
			countPtr =countPtr->NextPtr;
			count++;
		} while (countPtr != NULL);
	}
	
	printf("\n\t\t The Number of students = %d\n",count);
	//printf("\n\t\t The Number of students = %d\n",List1->size);
}


void middle_List()
{
	u8 flag,count;
	List_t *ListPtr=List1;
	Node_t* fastPtr=ListPtr->HeadPtr;
	Node_t* slowPtr=ListPtr->HeadPtr;
	if (ListPtr->HeadPtr == NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(fastPtr)
		{
			fastPtr=fastPtr->NextPtr;
			if (fastPtr == NULL)
			{
				flag =1;
				break;
			} 
			
			fastPtr=fastPtr->NextPtr;
			slowPtr=slowPtr->NextPtr;
			count++;
			}
			
			if (flag ==0) // length is even number
			{
				printf("\n list is even, the second middle is :\n");
			}
			printf("\n\t\t%-20s %-5s %-15s %-15s %-15s%-15s%-8s\n", "Name", "ID", "Date of Birth", "Address", "Phone", "Score","Height");
			printf("\t\t%-20s %-5d %d/%d/%-9d  %-15s %-15s%.2f           %.2f\n", slowPtr->Data_Students.Name, slowPtr->Data_Students.ID, slowPtr->Data_Students.DOB_Student.days, slowPtr->Data_Students.DOB_Student.months, slowPtr->Data_Students.DOB_Student.years, slowPtr->Data_Students.Address, slowPtr->Data_Students.Phone_Number, slowPtr->Data_Students.Student_Score,slowPtr->Data_Students.height);
		
	}
	
}
