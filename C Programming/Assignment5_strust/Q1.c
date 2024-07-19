#include <stdio.h>

typedef struct 
{
	char name[40];
	int roll_namber;
	float marks;
}student_t ;

void main ()
{
	student_t student1;
	printf("Enter information of students: \n\n" );
	printf("Enter name: ");
	scanf("%s",&student1.name);
	printf("Enter roll number: ");
	scanf("%d",&student1.roll_namber);
	printf("Enter marks: ");
	scanf("%f",&student1.marks	);
	
	printf("Display Information \n");
	printf("name: %s\n",student1.name);
	printf("Roll: %d\n",student1.roll_namber);
	printf("Marks: %.3f\n",student1.marks);
}