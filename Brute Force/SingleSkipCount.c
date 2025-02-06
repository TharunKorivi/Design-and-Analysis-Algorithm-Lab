#include<stdio.h>
#include<string.h>
void main()
{
    char sup[] = "jhgabcdejklahcuehjkjk";
    char sub[] = "ace";
    int count=0,m=strlen(sup),n=strlen(sub);
    for(int i=0;i<m-n+1;i++)
    {
        if(sup[i]==sub[0])
        {
            int f=0,k=i;
            for(int j=0;j<n;j++)
            {
                if(sub[j]!=sup[k])
                {
                    f=1;
                    break;
                }  
                k+=2;
            }
            if(f==0)
            {
                count++;
            }
        }
    }
    printf("No. of occurences of sub string when single char skipped : %d.\n",count);
}
