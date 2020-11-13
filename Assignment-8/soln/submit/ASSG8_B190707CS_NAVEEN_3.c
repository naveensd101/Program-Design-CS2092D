/*Write a menu driven program to construct an ExpressionTree T(it is a binary tree in which each
internal node corresponds to the operator and each leaf node corresponds to the operand) for a
given postfix expression e and perform the tree traversal operations (Inorder, Preorder and Post
order) on T. Each node x of T is an object with an attribute data, which is either an operator or an
operand of the expression and two pointer attributes: left and right pointing to the left and right
child of x respectively. An attribute T.root points to the root node of the tree T. Your program
must contain the following functions:
2
• Main() - repeatedly reads a character `e', `i', `p', `s', or `t' from the terminal and calls the
sub-functions appropriately until character `e' is entered.
• Construct-Tree(e) that takes as input a postx expression e, converts it into an expression
tree T and returns a pointer to the root of T.
• Inorder(T) that takes as input an expression tree T and prints the data in the nodes of T
in inorder.
• Preorder(T) that takes as input an expression tree T and prints the data in the nodes of T
in preorder.
• Postorder(T) that takes as input an expression tree T and prints the data in the nodes of
T in postorder.
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct tNode {
    char el;
    struct tNode *l;
    struct tNode *r;
    struct tNode *p;
};
struct tree {
    struct tNode *root;
};
struct sNode {
    struct tNode *pointTo;
    struct sNode *next;
};
struct stack {
    struct sNode *head;
};

int stackEmpty (struct stack *s) {
    return(s->head == NULL ? 1 : 0);
}
struct sNode *createSNode(char c) {
    struct sNode *ptr = (struct sNode *)malloc(sizeof(struct sNode));
    struct tNode *tPtr = (struct tNode *)malloc(sizeof(struct tNode));
    tPtr->el = c;
    tPtr->l = NULL;
    tPtr->p = NULL;
    tPtr->r = NULL;

    ptr->pointTo = tPtr;
    ptr->next = NULL;
    return ptr;
}
void push(struct stack *s, struct sNode *x) {
    x->next = s->head;
    s->head = x;
}
struct tNode *pop(struct stack *s) {
    if(stackEmpty(s)) return NULL;
    struct sNode *ptr = s->head;
    s->head = s->head->next;

    ptr->next = NULL;
    struct tNode *res = ptr->pointTo;
    free(ptr);
    return res;
}

int isOperator(char str) {
    switch (str) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 1;
        case '/':
            return 1;
        default :
            return 0;
    }
    return 0;
}

struct tree *constructTree(char str[]) {
    struct tree *T = (struct tree *)malloc(sizeof(struct tree));
    T->root = NULL;
    struct stack s;
    s.head = NULL;

    for(int i = 0; str[i] != '\0'; ++i) {
        if(isOperator(str[i])) {
            struct tNode *a = pop(&s);
            struct tNode *b = pop(&s);

            struct sNode *x = (struct sNode *)malloc(sizeof(struct sNode));
            x = createSNode(str[i]);
            x->pointTo->l = b;
            x->pointTo->r = a;
            push(&s, x);
        }
        else if(((int)str[i]>=(int)'a'&&(int)str[i]<=(int)'z')||(int)str[i]>=(int)'A'&&(int)str[i]<='Z'){
            struct sNode *x = createSNode(str[i]);
            push(&s, x);            
        }
    }
    T->root = pop(&s);
    return T;
}

void inorder(struct tNode * T) {
    if(T!=NULL) {
        inorder(T->l);
        printf("%c", T->el);
        inorder(T->r);
    }
    // printf("\n");
}
void preorder(struct tNode * T) {
    if(T!=NULL) {
        printf("%c", T->el);
        preorder(T->l);
        preorder(T->r);
    }
    // printf("\n");
}
void postorder(struct tNode *T) {
    if(T!=NULL) {
        postorder(T->l);
        postorder(T->r);
        printf("%c", T->el);
    }
    // printf("\n");
}

int main() {
    struct tree *T = (struct tree *)malloc(sizeof(struct tree));
    T->root = NULL;

    int canwe = 1;
    while(canwe) {
        char isit;
        scanf("%c", &isit);
        switch(isit) {
            case 'e':
            {
                char *exp = (char *)malloc(sizeof(char)*100000);
                scanf("%[^\n]%*c", exp);
                T = constructTree(exp);
                assert(T);
                break;
            }
            case 'i':
            {
                // assert(T->root);
                inorder(T->root);
                printf("\n");
                break;
            }
            case 'p':
            {
                preorder(T->root);
                printf("\n");
                break;
            }
            case 's':
            {
                postorder(T->root);
                printf("\n");
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


