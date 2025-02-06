#include<stdio.h>
#include<string.h>

void main()
{
    char sup[] = "abcdefghijklmn";
    char sub[] = "ajjj";
    int count = 0,m=strlen(sup),n=strlen(sub);
    for(int i=0;i<m-n+1;i++)
    {
        if(sub[0]==sup[i])
        {
            int f=0,k=i;
            for(int j=0;j<n;j++)
            {
                if(sup[k]!=sub[j])
                {
                    f=1;
                    break;
                }
                k+=(j+2);
            }
            if(f==0)
            {
                count++;
            }
        }
    }
    printf("No. of occurences of sub string when multiple chars are skipped : %d.\n",count);
    
}
