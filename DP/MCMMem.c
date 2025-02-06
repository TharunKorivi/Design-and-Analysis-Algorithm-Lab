/*
        Matrix Chain Multiplication : Memorization approach
Statement : Given n matrices, multiply the matrices, find the least 
possible multiplication operations in all possible ways of multiplying 
them.
e.g. if 1 2 3 4 are matrices : possible ways of multiplying
    a) (1) * (2 3 4)
    b) (1 2) * (3 4)
    c) (1 2 3) * (4)
In all these find least no. of multiplication operations
*/    
    
#include<stdio.h>
#include<limits.h>

int a[10];
int t[10][10];

/*
                    Logic :
Recursive expression :
MCM(i,j) = min(for k=i to j-1 do { MCM(i,k) + MCM(k+1,j) 
+ ith row*jth col*kth col} )
*/


int mcm(int i,int j)
{
    if(t[i][j]!=-1)
            return t[i][j];
    if(i==j)
    {
        return t[i][j] = 0;
    }
    else
    {
        int min = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int val = mcm(i,k) + mcm(k+1,j) + a[i-1]*a[k]*a[j];
            if(val<min)
            {
                min = val;
            }
        }
        return t[i][j] = min;
    }
}

void main()
{
    int n;
    printf("Enter the no. of matrices : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            t[i][j] = -1;
        }
    }
    int minOp = mcm(1,n);
    printf("Minimum no of operations : %d\n",minOp);
}
