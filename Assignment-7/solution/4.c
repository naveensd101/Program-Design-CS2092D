#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int k;
    struct node *next;
};
struct queue
{
    struct node *head;
    struct node *tail;
};
int queueEmpty(struct queue *q)
{
    return (q->head == NULL && q->tail == NULL ? 1 : 0);
}
struct node *CreateNode(int k)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    (*newNode).k = k;
    // printf("%d\n", k);
    (*newNode).next = NULL;

    return newNode;
}
void enqueue(struct queue *q, struct node *x)
{
    if (queueEmpty(q))
    {
        q->head = x;
        q->tail = x;
    }
    else
    {
        q->tail->next = x;
        q->tail = x;
    }
}
void dequeue(struct queue *q)
{
    if (queueEmpty(q))
    {
        printf("-1\n");
        return;
    }
    else
    {
        if (q->head == q->tail)
        {
            struct node *pointer = q->head;
            // assert(pointer);
            q->head = NULL;
            q->tail = NULL;

            pointer->next = NULL;
            printf("%d\n", pointer->k);
            free(pointer);
        }
        else
        {
            struct node *pointer = q->head;
            // assert(pointer);
            q->head = q->head->next;
            
            pointer->next = NULL;
            printf("%d\n", pointer->k);
            free(pointer);
        }
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;

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
            enqueue(q, CreateNode(k));
            break;
        }
        case 'd':
        {
            dequeue(q);
            break;
        }
        case 'e':
        {
            if (queueEmpty(q))
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