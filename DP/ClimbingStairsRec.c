/*
    Problem : There are n stairs, a person standing at the bottom wants to climb stairs to reach the nth stair. The person can climb either 1 stair or 2 stairs at a timecount the number of ways that a person can reach at the top.
*/


int climbStairs(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return climbStairs(n-1) + climbStairs(n-2);
}


void main()
{
    int n;
    printf("Enter no of stirs : ");
    scanf("%d",&n);
    int count = climbStairs(n);
    printf("No of ways to climb : %d\n",count);
}

/*
Certainly! The logic used in the algorithm is based on the observation that to reach the `n`th step of the staircase, you have two options:

1. You can either come from the `(n-1)`th step by taking one step.
2. Or you can come from the `(n-2)`th step by taking two steps.

Given this observation, the number of distinct ways to reach the `n`th step is equal to the sum of the distinct ways to reach the `(n-1)`th step and the `(n-2)`th step.

Let's illustrate this with an example:

Suppose you want to find the number of distinct ways to climb a staircase with 4 steps. You can calculate it as follows:

- To reach the 4th step, you can either:
  - Come from the 3rd step by taking one step.
  - Come from the 2nd step by taking two steps.

So, the total number of distinct ways to reach the 4th step is the sum of the number of ways to reach the 3rd step and the number of ways to reach the 2nd step.

Similarly, the number of ways to reach the 3rd step can be calculated by considering the options from the 2nd and 1st steps, and so on until we reach the base cases where there are only 0, 1, or 2 step


We can easily find the recursive nature in the above problem. The person can reach nth stair from either (n-1)th stair or from (n-2)th stair. Hence, for each stair n, we try to find out the number of ways to reach n-1th stair and n-2th stair and add them to give the answer for the nth stair. Therefore the Recurrence relation for such an approach comes out to be : 

    ways(n) = ways(n-1) + ways(n-2)



*/
