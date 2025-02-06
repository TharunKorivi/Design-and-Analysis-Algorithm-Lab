/*
        Matrix Chain Multiplication : Recursive approach
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


int mcm(int i,int j)
{
    if(i==j)
    {
        return 0;
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
        return min;
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
    int minOp = mcm(1,n);
    printf("Minimum no of operations : %d\n",minOp);
}
