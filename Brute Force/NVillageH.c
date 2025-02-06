#include<stdio.h>
#include<math.h>
#include<limits.h>
struct Village
{
    int x,y;
};
void main()
{
    int n;
    printf("Enter no. of points : ");
    scanf("%d",&n);
    struct Village v[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter point %d x,y coordinates : ",(i+1));
        scanf("%d%d",&v[i].x,&v[i].y);
    }
    int ind;
    double avgMin = INT_MAX,d;
    for(int i=0;i<n;i++)             
    {
        double sum = 0;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            d = sqrt(pow((v[j].x-v[i].x),2)+pow((v[j].y-v[i].y),2));
            sum+=d;
        }
        double avg = sum/(n-1);
        if(avgMin>avg)
        {
            avgMin = avg;
            ind = i;
        }
    }
    printf("Hospital should be established at village coordinates : (%d,%d) , avg min %lf",v[ind].x,v[ind].y,avgMin);
}
