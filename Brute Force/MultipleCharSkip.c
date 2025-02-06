#include<stdio.h>
#include<string.h>

void main()
{
    char sup[] = "abcdcdefghijklmn";
    char sub[] = "ajjj";
    int f=0,m = strlen(sup),n = strlen(sub),ind;
    for(int i=0;i<m-n+1;i++)
    {
        if(sup[i]==sub[0])
        {
            int k=i;
            int f1=0;
            for(int j=0;j<n;j++)
            {
                
                if(sub[j]!=sup[k])
                {
                    f1=1;
                    break;
                }
                k+=(j+2); // k = k +j+2  j:no of characters to skip
            }
                if(f1==0)
                {
                    f=1;
                    ind = i;
                }
        }
    }
    if(f==1)
    {
        printf("Sub string matched when multiple chars are skipped at index %d\n",ind);
    }
    else
    {
        printf("Sub string doesn't match when multiple char are skipped.\n");
    }

}
