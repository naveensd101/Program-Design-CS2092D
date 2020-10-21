#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
//assuming distinct elements
//-----------------------------------------------------------------------------------------------------------
struct node
{
    struct node *prev;
    int k;
    struct node *next;
};

struct list
{
    struct node *head;
};
//-----------------------------------------------------------------------------------------------------------
//CREATE-NODE(k)
struct node *CreateNode(int k)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->k = k;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}
//LIST-INSERT-FRONT(L,x)
void ListInsertFront(struct list *l, struct node *x)
{
    if (l->head != NULL)
    {
        (l->head)->prev = x;
    }
    x->next = l->head;
    l->head = x;
}
//LIST-INSERT-TAIL(L,x)
void ListInsertTail(struct list *l, struct node *x)
{
    if (l->head == NULL)
        ListInsertFront(l, x);
    else
    {
        struct node *pointer = l->head;
        while (pointer->next != NULL)
            pointer = pointer->next;

        x->prev = pointer;
        pointer->next = x;
    }
}
//LIST-SEARCH(L, k)
struct node *ListSearch(struct list *l, int k)
{
    struct node *pointer = l->head;
    //empty then do this
    if (pointer == NULL)
        return NULL;
    else
    {
        while (pointer != NULL)
        {
            if (pointer->k == k)
            {
                return pointer;
            }
            pointer = pointer->next;
        }
    }
    return NULL;
}
//LIST-INSERT-AFTER(L,x,y)
void ListInsertAfter(struct list *l, struct node *x, struct node *y)
{
    if (y == NULL)
        return;
    x->next = y->next;
    x->prev = y;
    // assert(y->next);
    // assert(y->next->prev);
    (y->next) ? y->next->prev = x : 0;
    y->next = x;
}
//LIST-INSERT-BEFORE(l, x, y)
void ListInsertBefore(struct list *l, struct node *x, struct node *y)
{
    if (y == NULL)
        return;
    struct node *pointer = l->head;
    if (pointer == y)
        ListInsertFront(l, x);
    else
    {
        // printf("hi\n");
        x->prev = y->prev;
        x->next = y;
        y->prev->next = x;
        y->prev = x;
    }
}
//LIST-DELETE(L, x)
void ListDelete(struct list *l, struct node *x)
{
    if (x == NULL)
    {
        printf("-1\n");
        return;
    }
    struct node *prev = x->prev;
    struct node *next = x->next;
    if (prev == NULL && next == NULL)
    {
        //only one element
        l->head = NULL;
        printf("%d\n", x->k);
        free(x);
        return;
    }
    else if (prev == NULL && next != NULL)
    {
        //first element
        next->prev = NULL;
        l->head = next;

        x->next = NULL;
        printf("%d\n", x->k);
        free(x);
        return;
    }
    else if (next == NULL && prev != NULL)
    {
        //last element
        prev->next = NULL;

        x->prev = NULL;
        printf("%d\n", x->k);
        free(x);
        return;
    }
    else
    {
        //middle element
        prev->next = next;
        next->prev = prev;

        x->prev = NULL;
        x->next = NULL;
        printf("%d\n", x->k);
        free(x);
        return;
    }
}
//LIST-DELETE-FIRST(L)
void ListDeleteFirst(struct list *l)
{
    if (l->head == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        ListDelete(l, l->head);
    }
}
//LIST-DELETE-LAST(L)
void ListDeleteLast(struct list *l)
{
    if (l->head == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        struct node *pointer = l->head;
        while (pointer != NULL)
        {
            if (pointer->next == NULL)
            {
                ListDelete(l, pointer);
                return;
            }
            pointer = pointer->next;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
int main()
{
    struct list *l = (struct list *)malloc(sizeof(struct list));
    l->head = NULL;

    int canwe = 1;
    while (canwe)
    {
        //for printing xD
        // struct node *pointer = l->head;
        // int count = 0;
        // while (pointer != NULL)
        // {
        //     uintptr_t prev = (uintptr_t)(void *)pointer->prev;

        //     uintptr_t next = (uintptr_t)(void *)pointer->next;
        //     // printf("%d)%" PRIuPTR " %d %" PRIuPTR "\n", count++, prev, pointer->k, next);
        //     printf("%d)%d ", count++, pointer->k);
        //     pointer = pointer->next;
        // }
        // printf("\n");
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'f':
        {
            int k;
            scanf("%d", &k);
            ListInsertFront(l, CreateNode(k));
            break;
        }
        case 't':
        {
            int k;
            scanf("%d", &k);
            ListInsertTail(l, CreateNode(k));
            break;
        }
        case 'a':
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ListInsertAfter(l, CreateNode(a), ListSearch(l, b));
            break;
        }
        case 'b':
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ListInsertBefore(l, CreateNode(a), ListSearch(l, b));
            break;
        }
        case 'd':
        {
            int a;
            scanf("%d", &a);
            ListDelete(l, ListSearch(l, a));
            break;
        }
        case 'i':
        {
            ListDeleteFirst(l);
            break;
        }
        case 'l':
        {
            ListDeleteLast(l);
            break;
        }
        case 's':
        {
            int a;
            scanf("%d", &a);
            struct node *pointer = ListSearch(l, a);
            if (pointer == NULL)
                printf("-1\n");
            else
                printf("1\n");
            break;
        }
        case 'e':
        {
            canwe = 0;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}