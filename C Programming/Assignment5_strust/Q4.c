#include <stdio.h>

typedef struct
{
	char name[40];
	
	float marks;
}student_t ;

void main ()
{
	student_t student[5];
	printf("Enter information of students: \n" );
	for (int i=0;i<5;i++)
	{
		printf("For Roll number %d\n",i+1);
		printf("Enter name: ");
		scanf("%s",&student[i].name);
		
		printf("Enter marks: ");
		scanf("%f",&student[i].marks	);
	}
	printf("\n\n");
	
	printf("Display Information \n");
	
	for (int i=0;i<5;i++)
	{
		printf("For Roll number %d\n",i+1);
		printf("name: %s\n",student[i].name);
		printf("Marks: %.3f\n",student[i].marks);
		printf("\n");
	}
	
}