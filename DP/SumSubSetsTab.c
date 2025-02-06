/*
For given array elements, Find the no. of subsets which sums up to given target sum         
                        SubSets : DP - Tabulation approach
*/

#include<stdio.h>

#define Max 50

int subSets(int a[],int n,int s)
{
    int mem[n+1][s+1];;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(j==0)
            {
                mem[i][j] = 1; 
            }
            else if(i==0)
            {
                mem[i][j] = 0;
            }
            else if(a[i-1]<=j)
            {
                mem[i][j] = mem[i-1][j-a[i-1]] + mem[i-1][j];
            }
            else
            {
                mem[i][j] = mem[i-1][j];
            }
        }
    }
    return mem[n][s];
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
    
    int noSets = subSets(a,n,sum);
    printf("No of subsets : %d\n",noSets);
}
