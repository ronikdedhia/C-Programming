#include <stdio.h>
int ascendingBinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descendingBinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findBitonicPoint(int arr[], int n, int l, int r)
{
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, mid, r);
    }
    else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, l, mid);
    }
    return bitonicPoint;
}

int searchBitonic(int arr[], int n, int key, int index)
{
    if (key > arr[index])
        return -1;

    else if (key == arr[index])
        return index;

    else
    {

        int temp = ascendingBinarySearch(arr, 0, index - 1, key);
        if (temp != -1)
        {
            return temp;
        }

        return descendingBinarySearch(arr, index + 1, n - 1, key);
    }
}

int searchShiftPoint(int arr[], int index, int n)
{
    for (int i = index; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
            return i;
    }
    return -1;
}

int isAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int isDescending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void print(int x)
{
    if (x == -1)
        printf("Element Not Found\n");
    else
        printf("Element Found at index %d \n", x);
}

int main()
{
    int n, key, index;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter The Value To Search: ");
    scanf("%d", &key);

    if (isAscending(arr, n))
    {
        int x = ascendingBinarySearch(arr, 0, n - 1, key);
        print(x);
    }
    else if (isDescending(arr, n))
    {
        int x = descendingBinarySearch(arr, 0, n - 1, key);
        print(x);
    }

    else
    {
        index = findBitonicPoint(arr, n, 0, n - 1);
        int s = searchShiftPoint(arr, index + 1, n);
        if (s == -1)
        {
            int x = searchBitonic(arr, n, key, index);
            print(x);
        }
        else
        {
            int x = searchBitonic(arr, s + 1, key, index);
            if (x != -1)
                printf("Element Found at index %d \n", x);
            else
            {
                int z = ascendingBinarySearch(arr, s + 1, n - 1, key);
                print(z);
            }
        }
    }
    return 0;
}
