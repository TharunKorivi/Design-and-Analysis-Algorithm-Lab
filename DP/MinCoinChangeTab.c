/* 
Given n number of denominations and some amount amt, and find the minimum 
number of coins to  sum up the amt using n coin denominations( you can include 
multiple coins of same denominations )
        Min Coin change : Tabular approach
*/

#include <stdio.h>
#include<limits.h>

int min(int a,int b)
{
        return a<b ? a:b;
}

int mcc(int dn[],int n,int amt)
{
        int a[n+1][amt+1];
        for(int i=0;i<=n;i++)
        {
                for(int j=0;j<=amt;j++)
                {
                        if(j==0)
                        {
                                a[i][j] = 0;
                        }
                        else if(i==0)
                        {
                                a[i][j] = INT_MAX - 1000;
                        }
                        else if(dn[i-1]<=j)
                        {
                                a[i][j] = min(1+a[i][j-dn[i-1]],a[i-1][j]);
                        }
                        else
                        {
                                a[i][j] = a[i-1][j];
                        }
                }
        }
        return a[n][amt];
}

void main()
{
    int n,amt;
    printf("Enter no of denominations : ");
    scanf("%d",&n);
    int dn[n];
    printf("Enter deominations : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&dn[i]);
    }
    printf("Enter amount : ");
    scanf("%d",&amt);
    int minCoins = mcc(dn,n,amt);
    printf("Min coins : %d\n",minCoins);

}
