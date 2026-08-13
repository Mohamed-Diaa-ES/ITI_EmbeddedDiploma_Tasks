#include <stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Please Enter Number1: "); scanf("%d",&num1); 
    printf("Please Enter Number2: "); scanf("%d",&num2); 
    printf("Please Enter Number3: "); scanf("%d",&num3); 

    int GN;
    if(num1>num2)
    {
        if(num1>num3)
        {

            GN=num1;
        }else
        {
            GN=num3;
        }
    }else if(num2>num3)
    {
        GN=num2;
        
    }else
    {
        GN=num3;
    }
    printf("Greatest number is: %d ",GN);
    return 0;
}