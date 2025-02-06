/*

HC Problem statement : 

Given an undirected graph, the task is to determine whether the graph contains 
a Hamiltonian cycle or not. If it contains, then prints the path.

HC Definition :     Hamiltonian Cycle or Circuit in a graph G is a cycle that 
visits every vertex of G exactly once and returns to the starting vertex.


*/

#include <stdio.h>

#define Max 10
int flag = 0;

int isSafe(int graph[][Max], int arr[], int pos, int i, int n) {
    for (int j = 0; j < pos; j++) {
        if (arr[j] == i)
            return 0;
    }
    if (graph[arr[pos - 1]][i] != 1)
        return 0;
    if (pos == n - 1 && graph[i][arr[0]] != 1)
        return 0;
    return 1;
}

void cycle(int graph[][Max], int arr[], int pos, int src, int n) {
    if(pos==0) {
        arr[pos] = src;
        cycle(graph,arr,pos+1,src,n);
        return;
    }
    if (pos == n) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[0]); 
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(graph, arr, pos, i, n)) {
            arr[pos] = i;
            cycle(graph, arr, pos + 1, src, n);
        }
    }
}

void insert(int graph[][Max], int srce, int dest) {
    graph[srce][dest] = 1;
    graph[dest][srce] = 1;
}

int main() {
    int graph[Max][Max];
    int n, e;
    printf("Enter number of vertices, edges: ");
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        int srce, dest;
        printf("Enter edge between vertices: ");
        scanf("%d %d", &srce, &dest);
        insert(graph, srce, dest);
    }
    int src;
    int arr[n];
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    cycle(graph, arr, 0, src, n);
    if (!flag) {
        printf("Hamiltonian cycle doesn't exist\n");
    }
    return 0;
}
