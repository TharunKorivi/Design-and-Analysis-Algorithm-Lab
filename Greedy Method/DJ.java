import java.util.*;

public class DJ {

    static int minCostNode(int cost[],boolean visit[]) {
        int min = Integer.MAX_VALUE;
        int minidx = -1;
        for(int i=0;i<cost.length;i++) {
            if(!visit[i] && cost[i] < min) {
                min = cost[i];
                minidx = i;
            }
        }
        return minidx;
    }

    static int[] dj(int graph[][],int src) {
        int n = graph.length;
        int cost[] = new int[n];
        int parent[] = new int[n];
        boolean visit[] = new boolean[n];
        Arrays.fill(cost, Integer.MAX_VALUE);
        Arrays.fill(parent,-1);
        cost[src] = 0;
        parent[src] = -1;
        int k = n;
        while(k>=1) {
            int u = minCostNode(cost,visit);
            visit[u] = true;
            for (int v = 0; v < n; v++) {
                if(graph[u][v]!=0 && !visit[v] && cost[v]>graph[u][v] + cost[u]) {
                    cost[v] = graph[u][v] + cost[u];
                    parent[v] = u;
                }
            }
            k--;
        }
        return cost;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int graph[][]
        = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        System.out.println("Enter src vertex : ");
        int src = sc.nextInt();                
        int cost[] = dj(graph,src);
        System.out.println("Cost of all vertices : ");
        for(int i=0;i<cost.length;i++) {
            System.out.println("Vertex "+i+" : "+cost[i]);
        }
        sc.close();
    }
}