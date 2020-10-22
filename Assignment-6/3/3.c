#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//-----------------------------------------------------------------------------------------------------------
struct node
{
    int processID;
    char state[50];
    struct node *next;
};

struct PCBlist
{
    struct node *head;
};
//-----------------------------------------------------------------------------------------------------------
//CREATE-PCB(k)
struct node *CreatePcb(int k)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->processID = k;
    strcpy(newNode->state, "nill");
    newNode->next = NULL;

    return newNode;
}
//INSERT(L,x)
void Insert(struct PCBlist *l, struct node *x)
{
    x->next = l->head;
    l->head = x;
}
//LIST-SEARCH(L, k)
struct node *ListSearch(struct PCBlist *L, int k)
{
    struct node *pointer = L->head;
    //empty then do this
    if (pointer == NULL)
    {
        return NULL;
    }
    else
    {
        while (pointer != NULL)
        {
            if (pointer->processID == k)
            {
                return pointer;
            }
            pointer = pointer->next;
        }
    }
    return NULL;
}
//DELETE(L,x)
void Delete(struct PCBlist *l, struct node *x)
{
    if (x == NULL) // if empty list then x will be null
    {
        printf("-1\n");
        return;
    }
    struct node *pointer = l->head;
    if (l->head == x)
    {
        l->head = x->next;
        pointer->next = x->next;
        printf("%d\n", pointer->processID);
        free(pointer);
        return;
    }
    while (pointer != NULL)
    {
        if (pointer->next == x)
        {
            pointer->next = x->next;
            printf("%d\n", x->processID);
            free(x);
            return;
        }
        pointer = pointer->next;
    }
}
//GET-STATE(k,L)
void GetState(int k, struct PCBlist *l)
{
    struct node *pointer = ListSearch(l, k);
    if (pointer == NULL)
    {
        printf("-1\n");
    }
    else
    {
        printf("%s\n", pointer->state);
    }
}
//LIST-WAITING-PROCESSES(L)
void ListWaitingProcesses(struct PCBlist *L)
{
    if (L->head == NULL)
    {
        printf("-1\n");
        return;
    }
    struct node *pointer = L->head;
    int found = 0;
    while (pointer != NULL)
    {
        if (strcmp(pointer->state, "waiting") == 0)
        {
            found = 1;
            printf("%d ", pointer->processID);
        }
        pointer = pointer->next;
    }
    if(found == 1)
    {
        printf("\n");
    }
    if (found == 0)
    {
        printf("-1\n");
        return;
    }
}
//UPDATE-STATE(L,k,s)
void UpdateState(struct PCBlist *l, int k, char s[])
{
    struct node *pointer = ListSearch(l, k);
    if (pointer == NULL)
        return;
    else
        strcpy(pointer->state, s);
}
//-----------------------------------------------------------------------------------------------------------
int main()
{
    struct PCBlist *L = (struct PCBlist *)malloc(sizeof(struct PCBlist));
    L->head = NULL;

    int canwe = 1;
    while (canwe)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
        {
            int a;
            char b[50];
            scanf("%d %s", &a, b);
            struct node *newNode = CreatePcb(a);
            strcpy(newNode->state, b);
            Insert(L, newNode);
            break;
        }
        case 'd':
        {
            int a;
            scanf("%d", &a);
            Delete(L, ListSearch(L, a));
            break;
        }
        case 'g':
        {
            int a;
            scanf("%d", &a);
            GetState(a, L);
            break;
        }
        case 'l':
        {
            ListWaitingProcesses(L);
            break;
        }
        case 'u':
        {
            int a;
            char b[50];
            scanf("%d %s", &a, b);
            UpdateState(L, a, b);
            break;
        }
        case 'e':
        {
            canwe = 0;
            break;
        }
            // default:
            // printf("hI\n");
            //     break;
        }
        // struct node *pointer = L->head;
        // int count = 0;
        // while (pointer != NULL)
        // {
        //     printf("(%d)%d %s\n", ++count, pointer->processID, pointer->state);
        //     pointer = pointer->next;
        // }
        // printf("\n");
    }
    return 0;
}