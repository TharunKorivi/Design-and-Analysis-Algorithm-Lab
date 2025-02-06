#include<stdio.h>
#include<string.h>

void main()
{
    char sup[] = "abcdefukdefkdef";
    char sub[] = "fed";
    int f1 = 0,ind=0;
    for(int i=0;i<=strlen(sup)-strlen(sub);i++)
    {
        if(sup[i]==sub[strlen(sub)-1])
        {
            int f=0,k=i;
            for(int j=strlen(sub)-1;j>=0;j--)
            {
                if(sub[j]!=sup[k++])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                f1=1;
                ind = i;
            }
        }
    }
    if(f1==1)
    {
        printf("Reverse sub string match found at %d index.\n",ind);
    }
    else
    {
        printf("Reverse sub string match not found.\n");
    }
}