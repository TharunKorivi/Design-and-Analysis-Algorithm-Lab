#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
struct Point
{
    int x,y;
};


void swap(struct Point p[],int i,int j)
{
	struct Point temp = p[i];
        p[i] = p[j];
        p[j] = temp;
}

void qsortx(struct Point p[],int low,int high)
{
    if(low<high)
    {
        int i=low,j=high,pivot = p[low].x;
        struct Point temp;
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
            	swap(p,i,j);
            }
        }
        swap(p,low,j);
        qsortx(p,low,j-1);
        qsortx(p,j+1,high);
    }
}
void qsorty(struct Point p[],int low,int high)
{
    if(low<high)
    {
        int i=low,j=high,pivot = p[low].y;
        struct Point temp;
        while(i<j)
        {
            while(p[i].y<=pivot)
            {
                i++;
            }
            while(p[j].y>pivot)
            {
                j--;
            }
            if(i<j)
            {
                swap(p,i,j);

            }
        }
        swap(p,low,j);
        qsorty(p,low,j-1);
        qsorty(p,j+1,high);
    }
}
double bruteforce(struct Point p[],int start,int end)
{
    double min = INT_MAX,d;
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
double cpy(struct Point p[],int start,int end)
{
    if(end-start>2)
    {
        int mid = (start+end)/2;
        double ud = cpy(p,start,mid);
        double dd = cpy(p,mid+1,end);
        double d = ud>dd ? dd : ud;
        struct Point strip[10];
        int k=0;
        for(int i=start;i<=end;i++)
        {
            if(abs(p[mid].y-p[i].y)<d)
            {
                strip[k++] = p[i];
            }
        }
        double bd = bruteforce(strip,0,k-1);
        return bd>d ? d : bd;
    }
    else
    {
        return bruteforce(p,start,end);
    }
}
double cpx(struct Point p[],int start,int end)
{
    if(end-start>2)  
    {
        int mid = (start+end)/2;
        double ld = cpx(p,start,mid);
        double rd = cpx(p,mid+1,end);
        double d = ld>rd ? rd : ld;
        struct Point strip[20];
        int k=0;
        for(int i=start;i<=end;i++)
        {
            if(abs(p[mid].x-p[i].x)<d)
            {
                strip[k++] = p[i];
            }
        }
        qsorty(strip,0,k-1);
        double bd = cpy(strip,0,k-1);
        return bd>d ? d : bd;
    }
    else
    {
        return bruteforce(p,start,end);
    }
}
void main()
{
    int n;
    printf("Enter no. of points : ");
    scanf("%d",&n);
    struct Point p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter point %d coordinates : ",i+1);
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    qsortx(p,0,n-1);
    double min = cpx(p,0,n-1);
    printf("Min disance : %lf",min);
}
