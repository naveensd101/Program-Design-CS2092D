#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct tNode {
    int key;
    struct tNode *l;
    struct tNode *r;
    struct tNode *p;
};
struct tree {
    struct tNode *root;
};

struct node {
    struct tree *pointTo;
    struct node *next;
};
struct list {
    struct node *head;
};
void ListInsertFront(struct list *L, struct node *x)
{
    (*x).next = (*L).head;
    (*L).head = x;
}
struct tNode *createNode(int k) {
    struct tNode *newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->key = k;
    newNode->l = NULL;
    newNode->r = NULL;
    newNode->p = NULL;
    return newNode;
}
void insert(struct tree *t, struct tNode *z) {
    struct tNode *y = NULL;
    struct tNode *x = t->root;

    while(x != NULL) {
        y = x;
        if(z->key < x->key) x = x->l;
        else x = x->r; 
    }
    z->p = y;
    /** y stores the parrent node inside the loop 
     * if y is null that implies that 
     * z should be the root node 
     * since root is the only place where parent in null
    **/
    if(y == NULL) t->root = z;// tree was empty
    else if(z->key < y->key) y->l = z;
    else y->r = z;
}
struct node *CreateNode(struct tree *t) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->pointTo = t;
    ptr->next = NULL;
    return ptr;
}
void insertSet(struct list *L, struct tree *t) {
    ListInsertFront(L, CreateNode(t));
}

void inorderWalk(struct tNode *x) {
    if(x != NULL) {
        inorderWalk(x->l);
        printf("%d ", x->key);
        inorderWalk(x->r);
    }
}
void PrintCollection(struct list *L) {
    if(L == NULL) return;
    struct node *p = L->head;
    while(p != NULL) {
        if(p->pointTo != NULL) {
            inorderWalk(p->pointTo->root);
            printf("\n");
        }
        p = p->next;
    }
}

struct tNode *search(struct tree *t, int k) {
    struct tNode *x = t->root;
    while(x!= NULL && k!=x->key) {
        if(k < x->key) x = x->l;
        else x = x->r;
    }
    return x;
}
struct node *FindSet(struct list *L, int k) {
    if(L == NULL) {
        printf("-1\n");
        return NULL;
    }
    struct tNode *finder;
    struct node *ptr = L->head;
    while(ptr != NULL) {
        finder = search(ptr->pointTo, k);
        if(finder != NULL) {
            printf("%d\n", ptr->pointTo->root->key);
            return ptr;
        }
        ptr = ptr ->next;
    }
    printf("-1\n");
    return NULL;
}

void ListDelete(struct list *L, struct node *x)
{
    if (x == NULL)
    {
        // printf("-1\n");
        return;
    }
    struct node *pointer = L->head;
    if (L->head == x)
    {
        L->head = x->next;
        pointer->next = x->next;
        // printf("%d\n", pointer->k);
        // free(pointer);
        return;
    }
    while (pointer != NULL)
    {
        if (pointer->next == x)
        {
            pointer->next = x->next;
            // printf("%d\n", x->k);
            // free(x);
            return;
        }
        pointer = pointer->next;
    }
}
void treeDelete(struct tNode *ptr) {
    if(ptr != NULL) {
        treeDelete(ptr->l);
        treeDelete(ptr->r);
        ptr->l = NULL;
        ptr->r = NULL;
        ptr->key = 0;
        ptr->p = NULL;
        free(ptr);
    }
}
void delete(struct list *L, int k) {
    struct node *ptr = FindSet(L, k);
    ListDelete(L, ptr);
    if(ptr == NULL) return;
    if(ptr->pointTo != NULL)
        treeDelete(ptr->pointTo->root);
    
}

void inorderInsert(struct tree *t, struct tNode *p1, struct tNode *p2) {
    if(p2 != NULL) {
        inorderInsert(t, p1, p2->l);
        inorderInsert(t, p1, p2->r);
        insert(t, p2);
    }
}
void MergeSet(struct list *L, int k1, int k2) {
    struct node *p1 = FindSet(L, k1);
    struct node *p2 = FindSet(L, k2);
    if(p1 == NULL || p2 == NULL) return;
    if(p1->pointTo != NULL && p2->pointTo != NULL) 
    inorderInsert(p1->pointTo, p1->pointTo->root, p2->pointTo->root);
    if(p2->pointTo != NULL)
    treeDelete(p2->pointTo->root);
}
int main() {
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->head = NULL;

    int canwe = 1;
    while(canwe) {
        char c;
        scanf("%c", &c);
        switch (c) {
            case 'e': {
                canwe = 0;
                break;
            }
            case 'i': {
                int n;
                scanf("%d", &n);
                int k;
                struct tree *t = (struct tree *)malloc(sizeof(struct tree));
                t->root = NULL;
                for(int i = 0; i < n; ++i) {
                    scanf("%d", &k);
                    insert(t, createNode(k));
                }
                insertSet(L, t);
                break;
            }
            case 'p': {
                PrintCollection(L);
                break;
            }
            case 'f': {
                int k;
                scanf("%d", &k);
                FindSet(L, k);
                break;
            }
            case 'd': {
                int k;
                scanf("%d", &k);
                delete(L, k);
                break;
            }
            case 'm': {
                int k1, k2;
                scanf("%d %d", &k1, &k2);
                MergeSet(L, k1, k2);
                break;
            }
        }
    }
    return 0;
}