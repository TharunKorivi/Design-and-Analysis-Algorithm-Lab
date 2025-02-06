#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>

struct Point
{
    int x,y;
};

void quicksort(struct Point p[],int low,int high)
{
    if(low<high)
    {
        int i=low,j=high,pivot=p[low].x;
        while(i<j)
        {
            while(p[i].x<=pivot)
            {
                i++;
            }
            while(p[j].x>pivot)
            {
                j--;
            }
            if(i<j)
            {
                struct Point temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
        struct Point temp = p[low];
        p[low] = p[j];
        p[j] = temp;
        quicksort(p,low,j-1);
        quicksort(p,j+1,high);
    }
}
double bruteforce(struct Point p[],int start,int end)
{
    double  min = INT_MAX, d=0;
    for(int i=start;i<=end-1;i++)
    {
        for(int j=i+1;j<=end;j++)
        {
            d = sqrt(pow((p[j].x-p[i].x),2)+pow((p[j].y-p[i].y),2));
            if(min>d)
            {
                min = d; 
            }
        }
    }
    return min;
}
double cp(struct Point p[],int start,int end)
{
    
    if(end-start>2)
    {
        int mid = (start+end)/2;
        double ld = cp(p,start,mid); //divide left half and calculate min distance of it
        double rd = cp(p,mid+1,end); //divide right half and calculate min distance of it
        double d = ld>rd ? rd:ld; //assign min distance among two halves
        struct Point strip[20];
        int k=0;
        for(int i=start;i<=end;i++)
        {
            if(abs(p[mid].x-p[i].x)<d)
            {
                strip[k++] = p[i];
            }
        }
        double bd = bruteforce(strip,0,k-1);
        
        return bd>d?d:bd;
    }
    else
    {

        return bruteforce(p,start,end);
        
    }
}


void main()
{
    int n;
    printf("Enter no of points : ");
    scanf("%d",&n);
    struct Point p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter point %d : ",i+1);
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    quicksort(p,0,n-1);
    
    double min = cp(p,0,n-1);
    printf("Min distance : %lf ",min);
}

