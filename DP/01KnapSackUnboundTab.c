/* 0/1 KnapSack Unbounded DP - Tabular approach*/
#include<stdio.h>

int max(int a,int b)
{
    return a>b? a:b;
}
int ks(int wt[],int val[],int n,int w)
{
    int a[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                a[i][j] = 0;
            else if(wt[i-1]<=j)
                a[i][j] = max(val[i-1]+a[i][j-wt[i-1]],a[i-1][j]);
            else
                a[i][j] = a[i-1][j];    

        }
    }   
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
    return a[n][w];     
}
void main()
{
    int wt[] = {3,2,4,5};
    int val[] = {20,16,45,40};
    int n = sizeof(wt)/sizeof(int);
    int w = 8;
    int maxVal = ks(wt,val,n,w);
    printf("Max value of 0/1 KnapSack : %d\n",maxVal);
}