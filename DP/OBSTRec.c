#include <stdio.h>
#include <limits.h>

int freq[10], arr[10];

int sum(int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int obst(int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return freq[i];
    }
    int min = INT_MAX;
    for (int k = i; k <= j; k++) {
        int val = obst(i, k - 1) + obst(k + 1, j) + sum(i, j);
        min = val < min ? val : min;
    }
    return min;
}

void main() {
    int n;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter node data and its frequencies respectively:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i], &freq[i]);
    }
    printf("Optimal cost: %d\n", obst(0, n - 1));
}
