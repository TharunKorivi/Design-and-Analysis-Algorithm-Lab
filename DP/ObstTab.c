   
    
#include<stdio.h>
#include<limits.h>

int a[10],freq[10];
int n;

int sum(int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}




int obst(int n) {

    int dp[n][n];

    for(int d=0 ; d<n ; d++) {
        for(int i=0;i<n-d;i++) {
            int j = i+d;
            if(i==j) {
                dp[i][j] = freq[i];
            }
            else {
                int min = INT_MAX;
                for(int k=i;k<=j;k++) {
                    int left = (k==i) ? 0 : dp[i][k-1];
                    int right = (k==j) ? 0 : dp[k+1][j];
                    int val = left + right;
                    min = val < min ? val : min;
                }
                dp[i][j] = min + sum(i,j);
            }
        }
    }
    return dp[0][n-1];
}

void main()
{
    printf("Enter the no. of matrices : ");
    scanf("%d",&n);
    printf("Enter elements and frequencies : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&freq[i]);
    }
    int minSearchCost = obst(n);
    printf("Minimum no of operations : %d\n",minSearchCost);
}
