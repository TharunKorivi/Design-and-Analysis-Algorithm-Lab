#include<stdio.h>
#include<stdbool.h>

int arr[10];

bool ss(int n,int s)
{
    bool a[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(j==0)
                a[i][j] = true;
            else if(i==0)
                a[i][j] = false;
            else if(arr[i-1]<=j)
                a[i][j] = a[i-1][j-arr[i-1]] || a[i-1][j];
            else 
                a[i][j] = a[i-1][j];
        }           
    }
    return a[n][s];
}

bool equalSum(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i]; 
    }
    if(sum%2!=0)
    {
        return false;
    }
    else
    {
        return ss(n,sum/2);
    }
}

void main()
{
    int n;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(equalSum(n))
    {
        printf("Equal sum subsets partition is possible.\n");
    }
    else 
    {
        printf("Equal sum subsets partiton is not possible\n");
    }
}
