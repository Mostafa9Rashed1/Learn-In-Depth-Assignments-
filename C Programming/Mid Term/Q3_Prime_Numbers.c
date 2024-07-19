# include <stdio.h>

void Prime_numbers(int Num1,int Num2)
{
	int i;
	int j,flag=0;
	for (i=Num1;i<=Num2;++i)
	{
		
		for (j=2;j<=Num2/2;j++)
		{
			if (i%j == 0 )
			{
				break;
			}
			flag=1;
		}
		 if (flag==1)
		 {
			 printf(" %d",i);
		 }
	}
	
}


void main ()
{
	int frist_num, Last_num;
	printf("Enter two number that get prime numbers between : ");
	scanf("%d %d",&frist_num,&Last_num);
	Prime_numbers(frist_num,Last_num);
}