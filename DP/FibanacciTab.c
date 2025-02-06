/* Fibonacci series :   DP-tabular approach */

#include<stdio.h>

int fib(int n)
{
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i==0 || i==1)
        {
            a[i] = i;
        }
        else
        {
            a[i] = a[i-1] + a[i-2];
        }
    }
    return a[n];
}

void main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("nth term of fibonacci : %d\n",fib(n));
}