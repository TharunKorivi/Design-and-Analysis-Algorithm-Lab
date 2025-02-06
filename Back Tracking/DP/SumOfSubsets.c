#include<stdio.h>

int wt[10], a[10],w,ways = 0;

void check(int n)
{
    int ws = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            ws+=wt[i];
        }
    }
    if(ws==w)
    {
        ways++;
    }
}

void ss(int n,int pos)
{
    if(n==pos)
    {
        check(n);
        return;
    }
    for(int i=0;i<2;i++)
    {
        a[pos] = i;
        ss(n,pos+1);
    }
}

void main()
{
    int n;
    printf("Enter no. of items : ");
    scanf("%d",&n);
    printf("Enter wts : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);
    }
    printf("Enter target capacity : ");
    scanf("%d",&w);
    ss(n,0);
    printf("No of sub sets : %d\n",ways);
}