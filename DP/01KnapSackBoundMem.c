/* 0/1 KnapSack Bounded Problem using DP - memorization*/
#include<stdio.h>


#define MAX 50 



int max(int a,int b)
{
    return a>b?a:b;
}

int ks(int wt[],int val[],int n,int w,int a[][MAX])
{
    if(a[n][w]!=-1) return a[n][w];
    if(n==0 || w==0)
    {
        //a[n][w] = 0;
        return a[n][w] = 0;
    }
    if(wt[n-1]<=w)
    {
        return a[n][w] = max(val[n-1]+ks(wt,val,n-1,w-wt[n-1],a),ks(wt,val,n-1,w,a));
    }
    else
    {
        return a[n][w] = ks(wt,val,n-1,w,a);
        //return a[n][w];
    }
    
}

void main()
{
    int wt[] = {3,2,5,4};
    int val[] = {20,16,45,40};
    int w = 8;
    int n = sizeof(wt)/sizeof(int);
    int a[n+1][MAX];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=w;j++)
            a[i][j] = -1;
    int maxVal = ks(wt,val,n,w,a);
    printf("Maximum value : %d\n",maxVal);
}
