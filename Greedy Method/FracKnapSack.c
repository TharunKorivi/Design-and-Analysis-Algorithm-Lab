#include<stdio.h>
struct Item
{
    int profit;//val
    int weight;
    float ratio; //profit by weight ratio : to sort based up
};
void sortItems(struct Item items[],int low,int high)
{
    if(low<high)
    {
         int i = low, j = high, pivot = items[low].ratio;
         struct Item temp;
        while(i<j)
        {
            while(items[i].ratio>=pivot)
            {
                i++;
            }
            while(items[j].ratio<pivot)
            {

                j--;
            }
            if(i<j)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
        temp = items[low];
        items[low] = items[j];
        items[j] = temp;
        sortItems(items,low,j-1);
        sortItems(items,j+1,high);
    }
} 

float knapSack(struct Item items[],int n,int capacity)
{
    sortItems(items,0,n-1); //sort items based on the ratio descending order
    float totalProfit = 0.0;
    for(int i=0;i<n;i++)
    {
        if(capacity>=items[i].weight)
        {
                totalProfit += items[i].profit;
                capacity-=items[i].weight;
            }
            else
            {
                totalProfit+=((float)capacity/(float)items[i].weight)*items[i].profit; 
                break;
            }

    }
    return totalProfit;
}
void main()
{
    int n;
    printf("Enter the no. of items : ");
    scanf("%d",&n);
    struct Item items[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the profit,weight of item %d : ",i+1);
        scanf("%d%d",&items[i].profit,&items[i].weight);
        items[i].ratio = (float)items[i].profit/items[i].weight;  
    }
    int capacity;
    printf("Enter capacity of knapsack : ");
    scanf("%d",&capacity);
    printf("Maximum profit : %f\n",knapSack(items,n,capacity));
}
