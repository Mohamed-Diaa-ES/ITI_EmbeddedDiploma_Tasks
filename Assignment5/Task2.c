#include <stdio.h>


int main()
{
int arr[10];
int sum=0;
for(int i=0;i<10;i++)
{
	printf("Enter Number%d: ",i+1);scanf("%d",&arr[i]);
	sum+=arr[i];
}

// for(int i=9;i>=0;i--)
// {
	printf("Summion is %d\n",sum);
	printf("Average is %f\n",sum/10.0);
// }
    return 0;
    
}
