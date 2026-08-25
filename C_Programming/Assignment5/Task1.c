#include <stdio.h>

void bubleSort(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
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

	int arr[10];
	int MinVal;
	int MaxVal;

	for (int i = 0; i < 10; i++)
	{

		printf("Enter Number%d: ", i + 1);
		scanf("%d", &arr[i]);
		if (i == 0)
		{
			// entering the first value in the array inside the
			// min and max values vars to prevent conflicting of written with what is
			// truely there.
			MinVal = arr[i];
			MaxVal = arr[i];
		}
		else if (arr[i] > MaxVal)
		{
			MaxVal = arr[i];
		}
		else if (arr[i] < MinVal)
		{
			MinVal = arr[i];
		}
	}

	printf("Value %d is the MinVal\n", MinVal);
	printf("Value %d is the MaxVal\n", MaxVal);

	return 0;
}
