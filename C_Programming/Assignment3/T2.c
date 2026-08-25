#include <stdio.h>

int main()
{
    int num;
    printf("Please Enter a Number: "); scanf("%d",&num);
    
    if(num<=0)
    {
        printf("%d* 1 = %d\n",num);
    }else
    {
        
    for(int i=1;i<=num;i++)
    {
        printf("%d* %d = %d\n",num,i,num*i);

    }
    }
    return 0;
}