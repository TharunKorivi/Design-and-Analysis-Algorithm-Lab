#include<stdio.h>
#include<stdbool.h>

int a[10];



void print(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void per(int n,int pos)
{
    if(n==pos)
    {
        print(n);
        return;
    }
    for(int i=0;i<2;i++)
    {
    	
        	a[pos] = i;
        	per(n,pos+1);
       
    }

}

void main()
{
    int n;
    printf("Enter no of bits : ");
    scanf("%d",&n);
    per(n,0);
}
