#include <stdio.h>

int main()
{
    int num1, num2;
    char op;
    printf("Please Enter Number1: ");
    scanf("%d", &num1);
    printf("Please Enter Number2: ");
    scanf("%d", &num2);
    printf("Please Enter operation symbol: \n");
    printf("Addi (+) \n");
    printf("Subt (-) \n");
    printf("Mult (*)  \n");
    printf("divi (/) \n");
    while (1)
    {

        scanf("%c", &op);
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            break;
        }
        else if (op == ' ' || op == '\n' || op == '\r')
        {
        }
        else
        {

            printf("Please Enter a Valid operation symbol!\n");
            printf("Addi (+) \n");
            printf("Subt (-) \n");
            printf("Mult (*)  \n");
            printf("divi (/) \n");
        }
    }

    switch (op)
    {
    case '+':
        printf("%d + %d= %f\n", num1, num2, (float)num1 + num2);
        break;
    case '-':
        printf("%d - %d= %f\n", num1, num2, (float)num1 - num2);
        break;
    case '*':
        printf("%d * %d= %f\n", num1, num2, (float)num1 * num2);
        break;
    case '/':
        printf("%d / %d= %f\n", num1, num2, (float)num1 / num2);
        break;
    }

    return 0;
}