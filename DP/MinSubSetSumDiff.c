#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

int arr[20]; // Maximum size of 2*n

int min(int a, int b) {
    return a < b ? a : b;
}

int mssd(int sum, int n) {
    bool a[n+1][sum+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                a[i][j] = true;
            } else if (i == 0) {
                a[i][j] = false;
            } else if (arr[i-1] <= j) {
                a[i][j] = a[i-1][j-arr[i-1]] || a[i-1][j];
            } else {
                a[i][j] = a[i-1][j];
            }
        }
    }
    int minm = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (a[n][i]) {
            minm = min(minm, abs(sum - 2 * i));
        }
    }
    return minm;
}

int main() {
    int n, sum = 0;
    printf("Enter n (length of one partition, total array length will be 2*n): ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    // Find the minimum absolute difference using subsets of size n
    int minDiff = mssd(sum, 2 * n);
    printf("Min subset difference is: %d\n", minDiff);
    return 0;
}

