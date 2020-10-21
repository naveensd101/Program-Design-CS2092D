#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//assuming distinct elements
//-----------------------------------------------------------------------------------------------------------
struct node
{
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
    (*newNode).k = k;
    // printf("%d\n", k);
    (*newNode).next = NULL;

    return newNode;
}
//LIST-INSERT-FRONT(L, x)
void ListInsertFront(struct list *L, struct node *x)
{
    (*x).next = (*L).head;
    (*L).head = x;
}
//LIST-INSERT-TAIL(L, x)
void ListInsertTail(struct list *L, struct node *x)
{
    //empty then do this
    if ((*L).head == NULL)
    {
        (*L).head = x;
    }
    else
    {
        struct node *pointer = (*L).head;
        while ((*pointer).next != NULL)
            pointer = (*pointer).next;
        (*pointer).next = x;
    }
}
//LIST-SEARCH(L,k)
struct node *ListSearch(struct list *L, int k)
{
    struct node *pointer = (*L).head;
    //empty then do this
    if (pointer == NULL)
    {
        return NULL;
    }
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
//LIST-INSERT-AFTER(L, x, y)
void ListInsertAfter(struct list *L, struct node *x, struct node *y)
{
    if (y == NULL)
    {
        return;
    }
    x->next = y->next;
    y->next = x;
}
//LIST-INSERT-BEFOR(L, x, y)
void ListInsertBefor(struct list *L, struct node *x, struct node *y)
{
    if (y == NULL)
    {
        return;
    }
    struct node *pointer = L->head;
    while (pointer != NULL)
    {
        if (pointer == y) //this means first element is y
        {
            L->head = x;
            x->next = y;
            break;
        }
        if (pointer->next == y)
        {
            pointer->next = x;
            x->next = y;
            break;
        }
        pointer = pointer->next;
    }
}
//LIST-DELETE(L,x)
void ListDelete(struct list *L, struct node *x)
{
    if (x == NULL)
    {
        printf("-1\n");
        return;
    }
    struct node *pointer = L->head;
    if (L->head == x)
    {
        L->head = x->next;
        pointer->next = x->next;
        printf("%d\n", pointer->k);
        free(pointer);
        return;
    }
    while (pointer != NULL)
    {
        if (pointer->next == x)
        {
            pointer->next = x->next;
            printf("%d\n", x->k);
            free(x);
            return;
        }
        pointer = pointer->next;
    }
}
//LIST-DELETE-FIRST(L)
void ListDeleteFirst(struct list *L)
{
    if (L->head == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        ListDelete(L, L->head);
    }
}
//LIST-DELETE-LAST(L)
void ListDeleteLast(struct list *L)
{
    if (L->head == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        struct node *pointer = L->head;
        while (pointer != NULL)
        {
            if (pointer->next == NULL)
            {
                ListDelete(L, pointer);
                return;
            }
            pointer = pointer->next;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
int main()
{
    struct list *L = (struct list *)malloc(sizeof(struct list));
    (*L).head = NULL;
    assert(L);

    int canwe = 1;
    assert(canwe);
    while (canwe)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'f':
        {
            int k;
            scanf("%d", &k);
            ListInsertFront(L, CreateNode(k));
            break;
        }
        case 't':
        {
            int k;
            scanf("%d", &k);
            ListInsertTail(L, CreateNode(k));
            break;
        }
        case 'a':
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ListInsertAfter(L, CreateNode(a), ListSearch(L, b));
            break;
        }
        case 'b':
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ListInsertBefor(L, CreateNode(a), ListSearch(L, b));
            break;
        }
        case 'd':
        {
            int a;
            scanf("%d", &a);
            ListDelete(L, ListSearch(L, a));
            break;
        }
        case 'i':
        {
            ListDeleteFirst(L);
            break;
        }
        case 'l':
        {
            ListDeleteLast(L);
            break;
        }
        case 's':
        {
            int a;
            scanf("%d", &a);
            struct node *pointer = ListSearch(L, a);
            if (pointer == NULL)
                printf("-1\n");
            else
                printf("%d\n", 1);
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
    // struct node *pointer = L->head;
    // int count = 0;
    // while (pointer != NULL)
    // {
    //     printf("%d)%d ", count++, pointer->k);
    //     pointer = pointer->next;
    // }
    // printf("\n");
    return 0;
}