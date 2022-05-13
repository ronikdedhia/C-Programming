#include <limits.h>
#include <stdio.h>
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}
int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input: ");
    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);
    printf("\nAnswer: %d ",
           MatrixChainOrder(arr, 1, n - 1));
    getchar();
    return 0;
}