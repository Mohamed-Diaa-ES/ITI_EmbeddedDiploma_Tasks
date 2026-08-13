#include <stdio.h>

int Factorial(int val)
{
    int res=1;
    for(int i=1;i<=val;i++)
    {
        res*=i;
    }
    return res;
} 
int nPr_Evaluation(int n,int r)
{
    if(n>=r)
  {
      return Factorial(n)/Factorial(n-r);
      
    }else 
    {
        printf(" r must be <=n!\n");
      return 0;
  }
} 


int main()
{
    int n,r;
    printf("Enter n: ");scanf("%d",&n);
    printf("Enter r: ");scanf("%d",&r);
    printf("(%d)P(%d) evaluation is: %d\n",n,r,nPr_Evaluation(n,r));

}