/* 
Given n number of denominations and some amount amt, and find the minimum 
number of coins to  sum up the amt using n coin denominations( you can include 
multiple coins of same denominations )
        Min Coin change : Recursive approach
*/

#include<stdio.h>
#include<limits.h>

int min(int a,int b)
{
    return a<b ? a:b;
}
int mcc(int dn[],int n,int amt)
{
    if(amt==0) 
        return 0;
    if(n==0)
        return INT_MAX-1000;
    if(dn[n-1]<=amt)
        return min(1+mcc(dn,n,amt-dn[n-1]),mcc(dn,n-1,amt));
    else
        return mcc(dn,n-1,amt);            

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