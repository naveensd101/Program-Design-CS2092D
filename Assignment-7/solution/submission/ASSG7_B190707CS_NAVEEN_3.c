#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *arr;
    int n;
};
struct queue
{
    struct array arr;
    int head;
    int tail;
};

int queue_full(struct queue *q)
{
    if (q->head == 0 && q->tail == q->arr.n - 1)
    {
        return 1;
    }
    else if (q->tail + 1 == q->head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int queue_empty(struct queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int k)
{
    if (queue_full(q))
    {
        printf("-1\n");
        return;
    }
    else
    {
        q->arr.arr[q->tail] = k;
        if (q->tail == q->arr.n - 1)
        {
            q->tail = 0;
        }
        else
        {
            q->tail++;
        }
    }
}
void dequeue(struct queue *q)
{
    if (queue_empty(q))
    {
        printf("-1\n");
        return;
    }
    else
    {
        printf("%d\n", q->arr.arr[q->head]);
        if (q->head == q->arr.n - 1)
        {
            q->head = 0;
        }
        else
        {
            q->head++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->arr.arr = (int *)malloc((n + 1) * sizeof(int));
    q->arr.n = n + 1;

    q->head = 0;
    q->tail = 0;

    int canwe = 1;
    while (canwe)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            enqueue(q, k);
            break;
        }
        case 'd':
        {
            dequeue(q);
            break;
        }
        case 'f':
        {
            if (queue_full(q))
            {
                printf("-1\n");
            }
            else
            {
                printf("1\n");
            }
            break;
        }
        case 'e':
        {
            if (queue_empty(q))
            {
                printf("-1\n");
            }
            else
            {
                printf("1\n");
            }
            break;
        }
        case 't':
        {
            canwe = 0;
            break;
        }
        }
    }
    return 0;
}