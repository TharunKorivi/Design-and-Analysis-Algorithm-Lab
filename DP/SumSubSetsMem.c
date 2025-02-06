/*
For given array elements, Find the no. of subsets which sums up to given target sum         
                        SubSets :  DP - Memorization approach
*/

#include<stdio.h>

#define Max 50

int subSets(int mem[][Max],int a[],int n,int s)
{
    if(mem[n][s]!=-1) return mem[n][s];
    if(s==0){
        mem[n][s] = 1;
        return mem[n][s];
    }
    if(n==0)
    {
        mem[n][s] = 0;
        return mem[n][s];
    }
    if(a[n-1]<=s)
    {
        mem[n][s] = subSets(mem,a,n-1,s-a[n-1]) + subSets(mem,a,n-1,s); 
        return mem[n][s];
    }
    else
    {
        mem[n][s] = subSets(mem,a,n-1,s);
        return mem[n][s];
    }
}
void main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum;
    printf("Enter target sum : ");
    scanf("%d",&sum);
    int mem[n+1][Max];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
            mem[i][j] = -1;
    int noSets = subSets(mem,a,n,sum);
    printf("No of subsets : %d\n",noSets);
}