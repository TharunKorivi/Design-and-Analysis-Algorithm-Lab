/*
For given array elements, Find the no. of subsets which sums up to given target sum         
                        SubSets - Recursive Approach
*/

#include<stdio.h>


int subSets(int a[],int n,int s)
{
    if(s==0) return 1;
    if(n==0) return 0;
    if(a[n-1]<=s)
        return subSets(a,n-1,s-a[n-1]) + subSets(a,n-1,s);
    else return subSets(a,n-1,s);
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
    int s;
    printf("Enter target sum : ");
    scanf("%d",&s);
    int noSets = subSets(a,n-1,s);
    printf("No of subsets : %d\n",noSets);
}