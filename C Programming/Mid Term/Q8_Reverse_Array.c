
#include <stdio.h>
void Reverse_Arr(int arr[100],int size);
int main() {
	int arr[100],size;
	printf ("Enter the Array size: ");
	scanf ("%d",&size);
	
	for (int i=0;i<size;i++)
	{
		printf ("Enter Element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	Reverse_Arr(arr,size);
	
	return 0;
}

void Reverse_Arr(int arr[100],int size)
{
	int reverse_arr[size];
	for (int i=0;i<size;i++)
	{
		reverse_arr[size-i-1]= arr[i];
	}
	
	for (int i=0;i<size;i++)
	{
		printf ("The element %d of the reverse array : %d\n", i+1,reverse_arr[i]);
	}

	
}