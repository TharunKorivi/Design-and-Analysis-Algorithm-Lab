/* Fibanacci nth term DP - memorization approach*/

#include<stdio.h>

int fib(int a[],int n)
{
    if(a[n]!=-1) return a[n];
    if(n<=1)
    {
        //a[n] = n;
        return a[n] = n;
    }
    else 
    {
        //a[n] = fib(a,n-1) + fib(a,n-2); 
        return a[n]=fib(a,n-1) + fib(a,n-2);
    }
}

void main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        a[i] = -1;
    }
    printf("nth term of fibanacci : %d\n",fib(a,5));
}
