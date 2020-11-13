#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    float cgpa;
    char name[50];
    struct node *next;
};

struct list
{
    struct node *head;
};

struct node *create(char name[], float cgpa)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->cgpa = cgpa;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

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

void combine(struct list *h1, struct list *h2, int n1, int n2)
{
    struct node *head1 = h1->head;
    struct node *head2 = h2->head;

    int i = 0;
    int flag = 1;
    while (i < n1 + n2)
    {
        printf("%d\n", i);

        if (head1->cgpa < head2->cgpa)
        {
            // printf("%s %f", head1->name, head1->cgpa);
            head1 = head1->next;
            i++;
        }
        else if(head1->cgpa >= head2->cgpa||head1->next == NULL)
        {
            // printf("%s %f", head2->name, head2->cgpa);
            ListInsertBefor(h1, head2, head1);
            head2 = head2->next;
            if(head1->next != NULL)
            {
                head1 = head1->next;
                flag = 0;
            }
            i++;
        }
    }
}

int main()
{
    struct list *l1 = (struct list *)malloc(sizeof(struct list));
    struct list *l2 = (struct list *)malloc(sizeof(struct list));
    l1->head = NULL;
    l2->head = NULL;

    int n1, n2;
    scanf("%d %d", &n1, &n2);
    for (int i = 0; i < n1; ++i)
    {
        char name[50];
        float cgpa;
        scanf("%s %f", name, &cgpa);
        ListInsertTail(l1, create(name, cgpa));
    }
    for (int j = 0; j < n2; ++j)
    {
        char name[50];
        float cgpa;
        scanf("%s %f", name, &cgpa);
        ListInsertTail(l2, create(name, cgpa));
    }
    printf("hi1\n");
    combine(l1, l2, n1, n2);
    printf("hi2\n");
    struct node *pointer = l1->head;
    int count = 0;
    while (count < n1+n2)
    {
        count++;
        printf("%s %.2f\n", pointer->name, pointer->cgpa);
        pointer = pointer->next;
    }
    return 0;
}