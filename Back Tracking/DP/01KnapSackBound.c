/* 0/1 KnapSack bounded */

#include<stdio.h>
#include<limits.h>

int wt[10],val[10],a[10],max=0,w;

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void check(int n)
{
    int vs = 0,ws = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            ws+=wt[i];
            vs+=val[i];
        }
    }
    if(ws<=w)
    {
        if(max<vs)
        {
            max = vs;
            print(n);
        }
    }

}

void ks(int n,int itmNo)
{
    if(n==itmNo)
    {
        check(n);
        return;
    }
    for(int i=0;i<2;i++)
    {
        a[itmNo] = i;
        ks(n,itmNo+1);
    }
}



void main()
{
    int n;
    printf("Enter no of wts : ");
    scanf("%d",&n);
    printf("Enter weights, its values : \n");
    for(int i=0;i<n;i++)
    {
        printf("Item no %d wt and val : ",i);
        scanf("%d%d",&wt[i],&val[i]);
    }
    printf("Enter the capacity of the bag : ");
    scanf("%d",&w);
    ks(n,0);
    printf("Max value : %d\n",max);
}
