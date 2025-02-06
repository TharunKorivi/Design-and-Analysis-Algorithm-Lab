/*
                    Optimal Merge Pattern 
                    
The optimal merge pattern problem is a classic problem in computer science and relates to the
 efficient merging of multiple sorted files into a single sorted file. 
The goal is to minimize the total cost of merging, where the cost is typically defined as the
total number of comparisons or the total time taken.

                        Problem Statement
You are given  sorted files with sizes  S_1, S_2, ..., S_n . The task is to merge these files 
into one single sorted file with the minimum possible cost. The cost to merge two files is 
the sum of their sizes, and each merge operation results in a new file whose size is the 
sum of the sizes of the files being merged.

Example
Consider three files with sizes 2, 3, and 4. There are several ways to merge them:

1. Merge files of sizes 2 and 3 to get a new file of size 5, then merge this new file with 
the file of size 4. The total cost is \( 2+3 + 5+4 = 14 \).
2. Merge files of sizes 3 and 4 to get a new file of size 7, then merge this new file with 
the file of size 2. The total cost is \( 3+4 + 7+2 = 16 \).

The first method results in a lower total cost, so it is the optimal merge pattern for this
 example.
*/
#include<stdio.h>

int arr[10];
int sum = 0;

void swap(int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void main() {
    int n;
    //a[] = {10,12,9,5,4,6,7,15,25}
    printf("Enter the array size : ");
    scanf("%d",&n);
    printf("Enter array elements : ");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    while(n>=2) {
        for(int i=0;i<n;i++) {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        int s = 0;
        int min = 0;
        for(int i=0;i<n;i++) {
            if(arr[i]<arr[min]) {
                min = i;
            }
        }
        swap(n-1,min);
        min = 0;
        for(int i=0;i<n-1;i++) {
            if(arr[i]<arr[min]) {
                min = i;
            }
        }
        swap(n-2,min); 
        s = arr[n-1] + arr[n-2];
        arr[n-2] = s;
        sum += s;
        
        n--;
    }
    printf("Sum : %d\n",sum);

}