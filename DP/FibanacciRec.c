#include<stdio.h>

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

void main()
{
    int n;
    printf("Enter n value : ");
    scanf("%d",&n);
    printf("nth term of fib : %d\n",fib(n));
}