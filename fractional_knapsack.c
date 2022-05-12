#include <stdio.h>
#include <math.h>
void main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    int weight[10];
    int value[10];
    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);
    printf("Enter the number of items:\n");
    scanf("%d", &no_items);
    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }
    for (i = 0; i < no_items; ++i)
        used[i] = 0;
    cur_weight = capacity;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;
        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];
        if (cur_weight >= 0)
            printf("%d - 100pct \n", item + 1);
        else
        {
            float item_percent = ((1 + (float)cur_weight / (float)weight[item]) * 100);

            printf("%d - %f pct \n", item + 1, ceil(item_percent));
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }
    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);
}