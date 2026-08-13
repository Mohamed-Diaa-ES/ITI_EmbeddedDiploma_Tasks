#include <stdio.h>

int main()
{
	int arr[10];
	int SumOdd = 0;
	int SumEven = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("Enter Number%d: ", i + 1);
		scanf("%d", &arr[i]);
		if (arr[i] % 2)
		{
			SumOdd += arr[i];
		}
		else
		{

			SumEven += arr[i];
		}
	}

	printf("Odd Summion is %d\n", SumOdd);
	printf("Even Summion is %d\n", SumEven);

	return 0;
}
