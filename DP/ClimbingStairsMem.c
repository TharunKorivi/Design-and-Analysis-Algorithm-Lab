#include<stdio.h>

int climbStairs(int a[],int n)
{
    if(a[n]!=-1) return a[n];
    if(n<=1)
    {
        a[n] = 1;
        return a[n];
    }
    else
    {
        a[n] = climbStairs(a,n-1) + climbStairs(a,n-2);
        return a[n];
    }
}

void main()
{
    int n;
    printf("Enter no of steps : ");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<=n;i++)
        a[i] = -1;
    int count = climbStairs(a,n);
    printf("No. of ways : %d\n",count);
}
