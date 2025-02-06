#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int profit;
    int weight;
    float ratio; //profit by weight ratio: to sort based upon
};

// Comparison function for sorting items by ratio in descending order
int compare(const void *a, const void *b)
{
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    if (itemA->ratio > itemB->ratio) return -1;
    if (itemA->ratio < itemB->ratio) return 1;
    return 0;
}

float knapSack(struct Item items[], int n, int capacity)
{
    // Sort items based on the ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);

    float totalProfit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            totalProfit += ((float)capacity / (float)items[i].weight) * items[i].profit;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item %d: ", i + 1);
        scanf("%d%d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    int capacity;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Maximum profit: %f\n", knapSack(items, n, capacity));
    return 0;
}

