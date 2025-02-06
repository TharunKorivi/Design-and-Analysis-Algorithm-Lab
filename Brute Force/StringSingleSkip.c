#include<stdio.h>
#include<string.h>
void main()
{
    char sup[] = "sdfghabcdeghjabchefdfg";
    char sub[] = "ace";
    int f=0,m=strlen(sup),n=strlen(sub),ind;
    for(int i=0;i<m-n+1;i++)
    {
        if(sup[i]==sub[0])
        {
            int f1=0,k=i;
            for(int j=0;j<n;j++)
            {
                if(sub[j]!=sup[k])
                {
                    f1=1;
                    break;
                }
                k+=2;
            }
            if(f1==0)
            {
                printf("%d\n",i);
                f=1;
                ind = i;
            }
        }
    }
    if(f==1)
        printf("String matched when single char skipped in btw at index %d\n",ind);
    else
        printf("String doesn't match when char skipped in btw.\n");
}