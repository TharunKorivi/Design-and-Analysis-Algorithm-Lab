#include<stdio.h>
#include<limits.h>
#include<math.h>
struct Village
{
    int x,y;
};

void main()
{
    int n;
    printf("Enter no. of villages points : ");
    scanf("%d",&n);
    struct Village v[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter village %d coordinates : ",i+1);
        scanf("%d%d",&v[i].x,&v[i].y);
    }
    int ind;
    double avgMax = INT_MIN,d;
    for(int i=0;i<n;i++)             
    {
        double sum = 0;
        for(int j=0;j<n;j++)
        {
            d = sqrt(pow((v[j].x-v[i].x),2)+pow((v[j].y-v[i].y),2));
            sum+=d;
        }
        double avg = sum/(n-1);
        if(avgMax<avg)
        {
            avgMax = avg;
            ind = i;
        }
    }
    printf("Pharmacy should be established at village coordinates : (%d,%d) , avg max  %lf",v[ind].x,v[ind].y,avgMax);
}

