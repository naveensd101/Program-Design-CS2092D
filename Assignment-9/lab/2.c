#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct tNode {
    int key;
    struct tNode *l;
    struct tNode *r;
    struct tNode *p;
};
struct tree {
    struct tNode *root;
};

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
struct tNode *search(struct tree *t, int k) {
    struct tNode *x = t->root;
    while(x!= NULL && k!=x->key) {
        if(k < x->key) x = x->l;
        else x = x->r;
    }
    return x;
}
void transplant(struct tree *T, struct tNode *u, struct tNode *v) {
    if(u->p == NULL) T->root = v;
    else if(u == u->p->l) u->p->l = v;
    else u->p->r = v;
    if(v!=NULL) v->p = u->p;
}
struct tNode *treeMin(struct tNode *x) {
    while(x != NULL && x->l != NULL) x = x->l;
    return x;
}
void delete(struct tree *T, struct tNode *z) {
    struct tNode *y = NULL;
    if(z->l == NULL) transplant(T, z, z->r);
    else if(z->r == NULL) transplant(T, z, z->l);
    else {
        y = treeMin(z->r);
        if(y->p != z) {
            transplant(T,y,y->r);
            y->r = z->r;
            y->r->p = y;
        }
        transplant(T, z, y);
        y->l = z->l;
        y->l->p = y;
    }
    //printf("%d\n", z->key);
    free(z);
}


void inorderHelp(struct tNode *r) {
    if(r != NULL) {
        inorderHelp(r->l);
        printf("%d ", r->key);
        inorderHelp(r->r);
    }
}
void inorder (struct tree *t) {
    inorderHelp(t->root);
    printf("\n");
}
void preorderHelp(struct tNode *r) {
    if(r != NULL) {
        printf("%d ", r->key);
        preorderHelp(r->l);
        preorderHelp(r->r);
    }
}
void preorder(struct tree *T) {
    preorderHelp(T->root);
    printf("\n");
}
void postorderHelp(struct tNode *r) {
    if(r!=NULL) {
        postorderHelp(r->l);
        postorderHelp(r->r);
        printf("%d ", r->key);
    }
}
void postorder(struct tree *T) {
    postorderHelp(T->root);
    printf("\n");
}

struct tree *combine(struct tree *T1, int k, struct tree *T2) {
    struct tree *res = (struct tree *)malloc(sizeof(struct tree));
    res->root = createNode(k);
    res->root->l = T1->root;
    res->root->r = T2->root;
    if(T1->root != NULL) T1->root->p = res->root;
    if(T2->root != NULL) T2->root->p = res->root;
    T1->root = NULL;
    T2->root = NULL;
    return res;
}

struct tree *combine2(struct tree *T1, struct tree *T2) {
    int k = INT_MAX;
    struct tree *bst = combine(T1, k, T2);
    delete(bst, bst->root);
    return bst;
}

void main() {
    struct tree *T1 = (struct tree *)malloc(sizeof(struct tree));
    T1->root = NULL;
    struct tree *T2 = (struct tree *)malloc(sizeof(struct tree));
    T2->root = NULL;

    int k;
    char c;
    do {
        scanf("%d%c", &k, &c);
        insert(T1, createNode(k));
    } while(c!='\n');

    do {
        scanf("%d%c", &k, &c);
        insert(T2, createNode(k));
    } while(c!='\n');

    struct tree *res = combine2(T1, T2);
    inorder(res);
}