#include<stdio.h>

int climbStairs(int n)
{
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=1)
            a[i] = 1;
        else
            a[i] = a[i-1] + a[i-2];    
    }
    return a[n];
}
void main()
{
    int n;
    printf("Enter no. of steps : ");
    scanf("%d",&n);
    int ways = climbStairs(n);
    printf("No. of ways : %d\n",ways);
}
