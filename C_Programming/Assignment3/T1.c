#include <stdio.h>

int main()
{
    int resByUser=0;
    printf("Enter the Result of the Next math expression: "); 
    printf(" 5*5= ?"); scanf("%d",&resByUser); 
    while(resByUser!=25)
    {
        printf("\a math expression value is wrong! Try Again!\n "); 
        printf(" 5*5= ?"); scanf("%d",&resByUser); 

    } printf(" You Entered the Correct Answer!");
    return 0;
}