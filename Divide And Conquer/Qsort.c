#include<stdio.h>


void swap(int a[],int i,int j )
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}  

int partition(int a[],int low,int high)
{
    int i=low,j=high,pivot=a[low];
    while(i<j)
    {
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
            swap(a,i,j);             
    }
    swap(a,j,low);
    return j;
}

void qsort(int a[],int low,int high)
{
    if(low<high)
    {
        int p = partition(a,low,high);
        qsort(a,low,p-1);
        qsort(a,p+1,high);
    }
}

void main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    printf("Sorted array : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
