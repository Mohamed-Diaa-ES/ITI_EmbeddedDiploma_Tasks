#include <stdio.h>

void bubleSort(int arr[],unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int arr[20]={1,2,3,45,6,8,98,65,65,65,1,2,3,45,6,8,98,65,65,65};
	printf("Before: ");
	for(int i=0;i<20;i++)
	{
		printf("%d ",arr[i]);

	}
	bubleSort(arr,20);
	printf("\nAfter: ");
	for(int i=0;i<20;i++)
	{
		printf("%d ",arr[i]);

	}

	return 0;
}
