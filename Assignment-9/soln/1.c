#include<stdio.h>
#include<stdlib.h>

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
    printf("%d\n", z->key);
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

void main() {
    struct tree *T = (struct tree *)malloc(sizeof(struct tree));
    T->root = NULL;

    int canwe = 1;
    while(canwe) {
        char c;
        scanf("%c", &c);
        switch (c) {
            
            case 'a': {
                int a;
                scanf("%d", &a);
                insert(T,createNode(a));
                break;
            }
            case 'e': {
                canwe = 0;
                break;
            }
            case 'd': {
                int a;
                scanf("%d", &a);
                struct tNode *ptr = search(T,a);
                if(ptr == NULL) printf("-1\n");
                else delete(T, ptr);
                break;
            }
            case 's': {
                int a;
                scanf("%d", &a);
                struct tNode *ptr = search(T, a);
                if(ptr == NULL) printf("-1\n");
                else printf("1\n");
                break;
            }
            case 'i': {
                inorder(T);
                break;
            }
            case 'p': {
                preorder(T);
                break;
            }
            case 't': {
                postorder(T);
                break;
            }
        }
    }
}