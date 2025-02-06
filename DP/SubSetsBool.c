/*

Given an array of elements and target sum. Find whether any elements of sums up to target sum or not ?

*/

#include<stdio.h>
#include<stdbool.h>                                  

bool subSets(int a[],int n,int s)
{
    if(s==0)
        return true;
    if(n==0)    
        return false;
    if(a[n-1]<=s)
    {
        return subSets(a,n-1,s-a[n-1]) || subSets(a,n-1,s);
    }     
    return subSets(a,n-1,s);
}
void main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int sum;
    printf("Enter taget sum : ");
    scanf("%d",&sum);
    bool isSub = subSets(a,n,sum);
    printf("Subsets : %d\n",isSub);
}
