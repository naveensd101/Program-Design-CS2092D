#include <stdio.h>
#include <stdlib.h>

struct node
{
    int k;
    struct node *next;
};

struct stack
{
    struct node *head;
};

int stack_empty(struct stack *s)
{
    return (s->head == NULL ? 1 : 0);
}
struct node *createNod(int k)
{
    struct node *pointer = (struct node *)malloc(sizeof(struct node));
    pointer->k = k;
    pointer->next = NULL;

    return pointer;
}
void push(struct stack *s, struct node *x)
{
    x->next = s->head;
    s->head = x;
}

void pop(struct stack *s)
{
    if (stack_empty(s))
    {
        printf("-1\n");
        return;
    }
    struct node *pointer = s->head;
    s->head = s->head->next;
    printf("%d\n", pointer->k);
    free(pointer);
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->head = NULL;

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
            push(s, createNod(k));
            break;
        }
        case 'd':
        {
            pop(s);
            break;
        }
        case 'e':
        {
            if (stack_empty(s))
                printf("-1\n");
            else
                printf("1\n");
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