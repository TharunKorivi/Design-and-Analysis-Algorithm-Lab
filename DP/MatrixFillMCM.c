#include<stdio.h>

int arr[10][10];

void fill(int n,int k)
{
    for(int d=0;d<n;d++)
    {
        for(int i=1;i<=n-d;i++)
       	{
            int j = i+d;
            arr[i][j] = k++; 
        }
        //c++;
    }
}

void main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    fill(n,1);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}
