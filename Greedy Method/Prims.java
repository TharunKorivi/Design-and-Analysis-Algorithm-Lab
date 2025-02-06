
import java.util.*;
public class Prims {
    static int minCostNode(boolean visit[],int cost[]){
        int min = Integer.MAX_VALUE;
        int minidx = - 1;
        for (int i = 0; i < cost.length; i++) {
            if(!visit[i] && cost[i]<min) {
                min = cost[i];
                minidx = i;
            }
        }
        return minidx;
    }
    static int[] prims(int graph[][],int src) {
        int n = graph.length;
        int cost[] = new int[n];
        int parent[] = new int[n];
        boolean visit[] = new boolean[n];
        Arrays.fill(cost,Integer.MAX_VALUE);
        Arrays.fill(parent,-1);
        parent[src] = -1;
        cost[0] = 0;
        int k = n;
        while(k>1) {
            int u = minCostNode(visit,cost);
            visit[u] = true;
            for(int v = 0 ; v < n; v++) {
                if(graph[u][v]!=0 && !visit[v] && cost[v] > graph[u][v]) {
                    cost[v] = graph[u][v];
                    parent[v] = u;
                }
            }
            k--;
        }
        return parent;
    }
    public static void main(String[] args) {
        int[][] graph = {
            {0, 10, 6, 5},  // Edges from vertex 0
            {10, 0, 0, 15}, // Edges from vertex 1
            {6, 0, 0, 4},   // Edges from vertex 2
            {5, 15, 4, 0}   // Edges from vertex 3
        };
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter src vertex : ");
        int src = sc.nextInt();
        System.out.println("MST : \nEdge | Weight");

        int parent[] = prims(graph, src);

        for (int i = 1; i < parent.length; i++) {
            System.out.println(parent[i]+" "+i+" : "+graph[i][parent[i]]);
        }

        sc.close();
    }

}