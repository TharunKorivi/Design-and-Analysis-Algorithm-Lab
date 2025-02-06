#include<stdio.h>

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
        printf("Enter point %d coordinates : ",i+1);
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int ec = 0;
    for(int i =0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a = p[j].y - p[i].y;
            int b = p[i].x - p[j].x;
            int c = p[i].x*p[j].y - p[i].y*p[j].x;
            int np = 0,nn = 0;
            for(int k=0;k<n;k++)
            {
                int val = a*p[k].x+b*p[k].y-c;
                if(val<0)
                {
                    nn++;
                }
                else if(val>0)
                {
                    np++;
                }
            }
            if(nn==0 || np==0)
            {
                ec++;
            }
        }
        
    }
    printf("No. of convex hall edges : %d",ec);
}
