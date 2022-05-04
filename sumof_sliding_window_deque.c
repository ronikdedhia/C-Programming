#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int front = -1, rear = -1;
int w;
void insert(int *dequeue, int value)
{
    if (rear == w - 1)
    {
        printf("Dequeue Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        dequeue[rear] = value;
    }
    else
    {
        rear++;
        dequeue[rear] = value;
    }
}
void delete (int *dequeue)
{
    if (front == -1 || front > rear)
    {
        printf("Dequeue Underflow\n");
    }
    else
    {
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}
int peek(int *dequeue)
{
    if (front == -1 || front > rear)
    {
        printf("Deueue is empty\n");
        return -1;
    }
    else
        return (dequeue[front]);
}
void display(int *dequeue)
{
    int i;
    if (front != -1 && front <= rear)
    {
        printf("Dequeue contains:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", dequeue[i]);
        }
    }
    else
        printf("Dequeue is empty\n");
}
void main()
{
    int *dequeue, *a, c, i, n, j;

    printf("Enter number of elements and window size:");
    scanf("%d %d", &n, &w);
    printf("Enter elements:");
    a = (int *)malloc(n * sizeof(int));
    dequeue = (int *)malloc(w * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Maxium of each window are:");
    for (i = 0; i <= n - w; i++)
    {
        insert(dequeue, i);
        c = w;
        for (j = i; c != 0; j++)
        {
            if (a[peek(dequeue)] < a[j])
            {
                delete (dequeue);
                insert(dequeue, j);
            }
            c--;
        }
        printf("%d  ", a[peek(dequeue)]);
        delete (dequeue);
    }
    getch();
}
