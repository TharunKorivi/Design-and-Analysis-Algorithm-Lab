/*0/1 Unbounded Knapsack DP - Memorization approach*/

#include<stdio.h>

#define Max 50

int max(int a,int b)
{
    return a>b?a:b;
}

int ks(int wt[],int val[],int a[][Max],int n,int w)
{
    if(a[n][w]!=-1) return a[n][w];
    if(n==0 || w==0)
    {
        return a[n][w] = 0;
        //return a[n][w];
    }
    if(wt[n-1]<=w)
    {
        return a[n][w] = max(val[n-1]+ks(wt,val,a,n,w-wt[n-1]),ks(wt,val,a,n-1,w));
        //return a[n][w];
    }
    else{
        return a[n][w] = ks(wt,val,a,n-1,w);
        //return a[n][w];
    }
}

void main()
{
    int wt[] = {3,2,4,5};
    int val[] = {20,16,45,40};
    int n = sizeof(wt)/sizeof(int);
    int w = 8;
    int a[n+1][Max];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=w;j++)
            a[i][j] = -1;
    int max = ks(wt,val,a,n,w);    
    printf("Max value of 0/1 unbounded Knapsack : %d\n",max);    
}
