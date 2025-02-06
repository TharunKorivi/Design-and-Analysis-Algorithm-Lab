#include<stdio.h>
#include<math.h>
#include<limits.h>
struct Point
{
    int x,y;
};
void main()
{
    int n;
    printf("Enter no. of points : ");
    scanf("%d",&n);
    struct Point p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter point %d x,y coordinates : ",(i+1));
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int min = INT_MAX,d,indI,indJ;
    for(int i=0;i<n-1;i++)             
    { 
        for(int j=i+1;j<n;j++)
        {
            d = sqrt(pow((p[j].x-p[i].x),2)+pow((p[j].y-p[i].y),2));
            if(d<min)
            {
                min = d;
                indI = i;
                indJ = j;
            }
        }
    }
    printf("Closest pair : (%d,%d) and (%d,%d) and distance is %d",p[indI].x,p[indI].y,p[indJ].x,p[indJ].y,min);
}
