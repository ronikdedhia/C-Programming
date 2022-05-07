#include <stdio.h>
int main()
{
    int n, p[10], i, wait[10], turn[10];
    float awt = 0.0, sum = 0.0, average = 0.0, summ = 0.0;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter the time of processes\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\nProcess\t Burst Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i + 1, p[i]);
    }
    printf("Time taken for each process is:\n");
    wait[0] = 0;
    for (i = 0; i < n; i++)
    {
        wait[i + 1] = wait[i] + p[i];
        printf("%d", wait[i]);
        sum = sum + wait[i];
    }
    awt = sum / n;
    printf("\nAverage Waiting Time is %f ", awt);
    for (i = 0; i < n; i++)
    {
        turn[i] = wait[i] + p[i];
    }
    printf("\nTurn Around Time is \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", turn[i]);
        summ = summ + turn[i];
    }
    average = summ / 4;
    printf("\nAverage turnaround time is %f", average);
    return 0;
}
