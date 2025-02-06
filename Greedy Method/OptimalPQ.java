/*
                    Optimal Merge Pattern 
                    
The optimal merge pattern problem is a classic problem in computer science and relates to the
 efficient merging of multiple sorted files into a single sorted file. 
The goal is to minimize the total cost of merging, where the cost is typically defined as the
total number of comparisons or the total time taken.

Problem Statement
You are given 
sorted files with sizes  S_1, S_2, ..., S_n . The task is to merge these files into one 
single sorted file with the minimum possible cost. The cost to merge two files is the sum 
of their sizes, and each merge operation results in a new file whose size is the sum of the 
sizes of the files being merged.

Example
Consider three files with sizes 2, 3, and 4. There are several ways to merge them:

1. Merge files of sizes 2 and 3 to get a new file of size 5, then merge this new file with 
the file of size 4. The total cost is \( 2+3 + 5+4 = 14 \).
2. Merge files of sizes 3 and 4 to get a new file of size 7, then merge this new file with 
the file of size 2. The total cost is \( 3+4 + 7+2 = 16 \).

The first method results in a lower total cost, so it is the optimal merge pattern for this
 example.

### Solution Approach
The optimal way to solve this problem is by using a greedy algorithm. The algorithm can be 
summarized as follows:

1. **Initialize** a min-heap with the sizes of the files.
2. **While** there is more than one file in the heap:
   - Extract the two files with the smallest sizes (the two root elements of the heap).
   - Merge these two files, and record the cost of this merge.
   - Insert the new merged file back into the heap.
3. **Sum** the costs of all merge operations to get the total minimum cost.

This approach ensures that the smallest files are merged first, which helps in minimizing 
the overall merging cost. The min-heap data structure allows for efficient extraction of 
the smallest elements and insertion of new elements, making the algorithm efficient.

                Complexity
The time complexity of this algorithm is  O(n log n) , where  n is the number
 of files. This complexity arises from the operations on the min-heap, such as insertion 
 and extraction, which take  O(log n) time each.

In summary, the optimal merge pattern problem focuses on finding the most cost-effective 
way to merge multiple sorted files into one sorted file, utilizing a greedy algorithm and 
a min-heap to achieve the minimum total merging cost.
*/


import java.util.Scanner;
import java.util.PriorityQueue;

public class OptimalPQ {
    public static int optimalMerge(int arr[]) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int val : arr) {
            minHeap.add(val);
        }

        int totalCost = 0;

        while(minHeap.size()>=2) {
            int first = minHeap.poll();
            int second = minHeap.poll();

            int merged = first + second;

            minHeap.add(merged);
            totalCost += merged;
        }
        return totalCost;
    }
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter array size : ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter file sizes : ");
         //a[] = {10,12,9,5,4,6,7,15,25}
        for(int i = 0;i<n;i++) {
            arr[i] = sc.nextInt();
        }
        int minCost = optimalMerge(arr);
        System.out.println("Minimum cost of merge : "+minCost);
        sc.close();
    }
}
