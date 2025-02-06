/*

Few points of x-y plane are given. Find the edges of convex hall (edges formed by pairs of 
points surrounding the other points)

*/

#include<stdio.h>

struct Point // user defined datatype for point to bind x,y coordinates
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
    int a,b,c,val;
    /*
            Formula for straight line passing through two 
            points (x1,y1) and (x2,y2)
                (x-x1)(x2-x1) = (y-y1)(y2-y1)  ===> ax + by = c
                 a = y2 - y1
                 b = x1 - x2 
                 c = x1y2 - y1x2
            Algorithm : 
                -> For every point find straight lines equation formed by other points
                        =>in that : all points coordinates are substituted in 
                        expression of straight line,
                        expression value is negative on one side of straight line
                        expression value is positive on other side of straight line
                        expression value is 0 if lies on line
                for an edge of convex hall only one of the side has points 
                so either number of points on one of the side must be = 0    
                                     
    */
    printf("Convex hull edges : \n");
    for(int i=0;i<n-1;i++)           
    {
        for(int j=i+1;j<n;j++)
        {
            a = p[j].y-p[i].y; // a = y2 - y1
            b = p[i].x-p[j].x; // b = x1 - x2
            c = p[i].x*p[j].y-p[i].y*p[j].x; // c = x1y2 - y1x2
            int np = 0, nn = 0;
            for(int k=0;k<n;k++)
            {
                val = a*p[k].x+b*p[k].y-c;
                if(val>0)
                {
                    np++;
                }
                else if(val<0)
                {
                    nn++;
                }
            }
            if(np==0 || nn==0)
            {
                printf("Edge : (%d,%d),(%d,%d)\n",p[i].x,p[i].y,p[j].x,p[j].y);
            }
        }
    }
}
