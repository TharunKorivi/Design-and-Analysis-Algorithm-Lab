#include<stdio.h>
#include<string.h>
void main()
{
    char sup[] = "abcabcabcdakcabcdyabcd";
    char sub[] = "abcd";
    int count = 0,m = strlen(sup),n = strlen(sub);
    for(int i=0;i<m-n+1;i++)
    {
        if(sup[i]==sub[0])
        {
            int f=0;
            for(int j=0;j<n;j++)
            {
                if(sup[i+j]!=sub[j])
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
    printf("Count of sub string occurences : %d",count);
}