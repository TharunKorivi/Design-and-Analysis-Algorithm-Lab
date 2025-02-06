#include<stdio.h>
#include<stdbool.h>

int a[10];

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

bool isSafe(int pos,int i)
{
    for(int j=0;j<pos;j++)
    {
        if(a[j]==i)
            return false;
    }
    return true;
}

void per(int n,int pos)
{
    if(n==pos)
    {
        print(n);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(isSafe(pos,i))
        {
            a[pos] = i;
            per(n,pos+1);
        }
    }
}

void main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    per(n,0);
}