public class Krushkals {

    static int findAnc(int parent[],int k) {
        while(k!=parent[k]) {
            k = parent[k];
        }
        return k;
    }

    static int[] findMinEdge(int graph[][]) {
        int min = Integer.MAX_VALUE;
        int arr[] = new int[2];
        for(int i=0;i<graph.length;i++) {
            for(int j=0;j<graph[0].length;j++) {
                if(graph[i][j] != 0 && graph[i][j] < min) {
                    min = graph[i][j];
                    arr[0] = i;
                    arr[1] = j;
                }
            }
        }
        return arr;
    }

    static boolean checkLoop(int parent[],int u,int v) {
        int pu = findAnc(parent,u);
        int pv = findAnc(parent,v);
        if(pu==pv) {
            return false;
        }
        else {
            parent[pv] = pu;
            return true;
        }
    }

    static void kru(int graph[][]) {
        int n = graph.length;
        int parent[] = new int[n];
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
        int k = n;
        while (k>1) {
            int arr[] = findMinEdge(graph);
            int u = arr[0];
            int v = arr[1];
            boolean loopNot = checkLoop(parent,u,v);
            if(loopNot) {
                System.out.println(u+" "+v+" : "+graph[u][v]);
                k--;
            }
            graph[u][v] = 0;
            graph[v][u] = 0;
            
        }
    }
    public static void main(String[] args) {
        int[][] graph = {
            {0, 10, 6, 5},  // Edges from vertex 0
            {10, 0, 0, 15}, // Edges from vertex 1
            {6, 0, 0, 4},   // Edges from vertex 2
            {5, 15, 4, 0}   // Edges from vertex 3
        };
        System.out.println("MST : \nEdge | Weight");
        kru(graph);
    }
}