#include<stdio.h>



int max(int a,int b)
{
    return a>b?a:b;
}

int ks(int wt[],int val[],int n,int w)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]<=w)
    {
        return max(val[n-1]+ks(wt,val,n-1,w-wt[n-1]),ks(wt,val,n-1,w));
    }    
    else 
        return ks(wt,val,n-1,w);
}


void main()
{
    int wt[] = {3,2,5,4};
    int val[] = {20,16,45,40};
    int n = sizeof(wt)/sizeof(int);
    int W = 8;
    printf("Max weight of 0/1 knapsack : %d\n",ks(wt,val,n,W));
}
