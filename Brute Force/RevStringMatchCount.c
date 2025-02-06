#include<stdio.h>
#include<string.h>
void main()
{
    char sup[] = "abcdefjdefjkkjdefkjhdef";
    char sub[] = "fed";
    int count = 0,m = strlen(sup),n = strlen(sub);
    for(int i=0;i<m-n+1;i++)
    {
        if(sup[i]==sub[n-1])
        {
            int f=0,k=i;
            for(int j=n-1;j>=0;j--)
            {
                if(sup[k++]!=sub[j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                count++;
            }
        }
    }
    printf("No of sub string occurences : %d\n",count);
}