#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 100
struct queue
{
    int front, rear;
    int items[QUEUESIZE];
};
int v, adj[100][100], visited[100];
int checkEmpty(struct queue *pq)
{
    if (pq->rear < pq->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int removeElement(struct queue *pq)
{
    return (pq->items[(pq->front)++]);
}
void insert(struct queue *pq, int x)
{
    if (pq->rear == QUEUESIZE - 1)
    {
        printf("QUEUE OVERFLOW,CANNOT INSERT");
        getch();
        exit(1);
    }
    pq->items[++(pq->rear)] = x;
}
int sequential(struct queue q, int key)
{
    int i = 0;
    while (i < QUEUESIZE)
    {
        if (key == q.items[i])
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}
void bfs(int k)
{
    int j;
    struct queue q;
    q.rear = -1;
    q.front = 0;
    insert(&q, k);
    while (!checkEmpty(&q))
    {
        k = removeElement(&q);
        visited[k] = 1;
        printf("%d ", k);
        for (j = 1; j <= v; j++)
        {
            if (adj[k][j] == 1)
            {
                if (visited[j] == 0 && (sequential(q, k)) == -1)
                {
                    insert(&q, j);
                }
            }
        }
    }
}
int main()
{
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d", &v);
    printf("ENTER THE VALUES OF VERTICES: \n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("IS VERTEX %d ADJACENT TO VERTEX %d?", i, j);
            printf("\nPRESS 1 FOR YES & 0 FRO NO: ");
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 1; i <= v; i++)
    {
        visited[i] = 0;
    }
    printf("TOPOLOGICAL ORDER OF VERTICES IS: ");
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
        }
    }
    return 0;
}