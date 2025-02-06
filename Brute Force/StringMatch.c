#include<stdio.h>
#include<string.h>
void main()
{
    char sup[] = "abcabcabcd";
    char sub[] = "abcd";
    int f1=0,ind=0;
    for(int i=0;i<=strlen(sup)-strlen(sub);i++)
    {
        if(sup[i]==sub[0])
        {
            int f=0;// 'f' for char mismatch after first sub char match
            for(int j=0;j<strlen(sub);j++)
            {
                if(sup[i+j]!=sub[j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                f1=1;
                ind = i;
                break;
            
            }
            
        }
    }
    if(f1==1)
        printf("Match found at %d.",ind);
    else
        printf("Match not found.");

}