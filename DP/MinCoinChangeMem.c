/* 
Given n number of denominations and some amount amt, and find the minimum 
number of coins to  sum up the amt using n coin denominations( you can include 
multiple coins of same denominations )
        Min Coin change : Memorization approach
*/

#include<stdio.h>
#include<limits.h>

#define Max 20

int min(int a,int b)
{
    return a<b ? a:b;
}

int mcc(int a[][Max],int dn[],int n,int amt)
{
    if(a[n][amt]!=-1)
        return a[n][amt];
    if(amt==0)
        return a[n][amt] = 0;
    if(n==0)
        return a[n][amt] = INT_MAX-1000;
    if(dn[n-1]<=amt)
        return a[n][amt] = min(1+mcc(a,dn,n,amt-dn[n-1]),mcc(a,dn,n-1,amt)); 
    else 
        return a[n][amt] = mcc(a,dn,n-1,amt);         
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
    int a[n+1][Max];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=amt;j++)
            a[i][j] = -1;
    int minCoins = mcc(a,dn,n,amt);        
    printf("Min coins : %d\n",minCoins);

}