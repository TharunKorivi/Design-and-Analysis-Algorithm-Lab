#include<stdio.h>

int a[5][5];

void fill(int c,int k)
{
    if(c<5)
    {
        for(int i=0;i<5-c;i++)
        {
            a[i][i+c] = k++;
        }
        fill(c+1,k);
    }
}
void main()
{

    fill(0,1);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]!=0)
                printf("%2d ",a[i][j]);
            else
                printf("   ");    
        }
        printf("\n");
    }

}
