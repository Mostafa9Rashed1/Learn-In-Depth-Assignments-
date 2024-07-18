#include <stdio.h>

void Prime_Numbers(int num1,int num2);
 
void main()
{
	int number1, number2 , Num_arr[100],interval ;
	printf("Enter two number (intervals): ");
	scanf("%d%d",&number1,&number2);
	interval = number2-number1;
	
	printf("Prime numbers between %d and %d are: ",number1,number2);
	Prime_Numbers(number1,number2);
	
}

void Prime_Numbers(int num1 ,int num2 )
{
	
	int j;
	for (int i=num1 ;i<num2; i++)
	{
		if (i <=1) continue;
		
		int flag=1;
		for (j=2; j<=i/2;j++)
		{
			
			if (i%j == 0 )
			{
				flag=0;
				break;
			}
		}
		 if (flag)
		 {
			 printf(" %d",i);
		 }
	}
	
}
