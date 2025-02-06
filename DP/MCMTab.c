/*
        Matrix Chain Multiplication : Tab approach
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

/*
                    Logic :
Recursive expression :
MCM(i,j) = min(for k=i to j-1 do { MCM(i,k) + MCM(k+1,j) 
+ ith row*jth col*kth col} )
*/



int mcm(int n)
{
    int m[n+1][n+1];
    for(int d=0;d<n;d++)
    {
        for(int i=1;i<=n-d;i++) 
        {
            int j = i+d;
            if(i==j)
            {
                m[i][j] = 0;
            }
            else
            {
                int min = INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int val = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];
                    if(val<min)
                    {
                        min = val;
                    }
                }
                m[i][j] = min;
            }
        }

    }
    return m[1][n];
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
    int minOp = mcm(n);
    printf("Minimum no of operations : %d\n",minOp);
}
