#include <stdio.h>

void bubleSort(int arr[], unsigned int n)
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
void swap_poiters(int *p1, int *p2)
{
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}
int main()
{

	int x = 1, y = 2, z = 3;
	int *p = &x, *q = &y, *r = &z;
	printf("before swapping: \n");
	printf("*p==%d and x ==%d\n", *p, x);
	printf("*q==%d and y ==%d\n", *q, y);
	printf("*r==%d and z ==%d\n", *r, z);
	//swapping logic in the assignment: (not really swapping)
	r = p;
	p = q;
	q = r;
	printf("After swapping: \n");
	printf("*p==%d and x ==%d\n", *p, x);
	printf("*q==%d and y ==%d\n", *q, y);
	printf("*r==%d and z ==%d\n", *r, z);

	return 0;
}
