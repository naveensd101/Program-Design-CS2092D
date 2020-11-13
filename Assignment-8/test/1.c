/*author: Naveen S D
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//------------------------------------------------------------------------------------------------------------
/*Write a program for converting a given infix expression to postfix form using STACK. Write a
function InfixToPostfix(e) which converts the given infix expression e to postfix expression and
returns the postfix expression.
*/

struct IPnode {
    char c;
    struct IPnode *next;
};
struct IPstack {
    struct IPnode *head;
};
int IPstackEmpty(struct IPstack *s) {
    return (s->head == NULL ? 1 : 0);
}
struct IPnode *createNode(char c) {
    struct IPnode *ptr = (struct IPnode *)malloc(sizeof(struct IPnode));
    ptr->c = c;
    ptr->next = NULL;
    return ptr;
}
void IPpush(struct IPstack *s, struct IPnode *x) {
    x->next = s->head;
    s->head = x;
}
char IPpop(struct IPstack *s) {
    if(IPstackEmpty(s)) {
        return '~';
    }
    struct IPnode *ptr = s->head;
    s->head=s->head->next;
    char c = ptr->c;
    ptr->next = NULL;
    free(ptr);
    return c;
}
char laElem(struct IPstack *s) {
    if(IPstackEmpty(s)) return '#';
    return s->head->c;
}

int isp(char c) {
    switch (c) {
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return -1;
}
int icp(char c) {
    switch (c) {
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '(':
            return 3;
    }
    return -1;
}

char *infixToPostfix(char str[]) {
    struct IPstack s;
    s.head = NULL;
    char *res = (char*)malloc(sizeof(char)*100000);
    int resptr = 0;
    
    for(int i = 0; str[i] != '\0'; ++i) {
        if(((int)str[i]>=(int)'a' && (int)str[i]<=(int)'z') || ((int)str[i]>='A' && (int)str[i]<='Z')) 
            res[resptr++] = str[i];
        else if(str[i] == ')') {
            while(laElem(&s) != '('){
                char y = IPpop(&s);
                res[resptr++] = y;
            }
            IPpop(&s);
        }
        else {
            char y = laElem(&s);
            if(icp(str[i]) > isp(y)) {
                IPpush(&s, createNode(str[i]));
            }
            else {
                while(IPstackEmpty(&s) == 0 && isp(laElem(&s)) >= icp(str[i])) {
                    res[resptr++] = IPpop(&s);
                }
                IPpush(&s, createNode(str[i]));
            }
        }
    }
    while(IPstackEmpty(&s) == 0) {
        res[resptr++] = IPpop(&s);
    }

    return res;
}
//------------------------------------------------------------------------------------------------------------

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

struct tree *createAssignmentTree(char str[]) {
    char *e = (char *)malloc(100000);
    int ept = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        if(i == 0 || i == 1 || i == strlen(str)-1) continue;
        e[ept++] = str[i];
    }
    e[ept++] = '\0';
    
    struct tree *T = constructTree(infixToPostfix(e));
    // inorder(T->root);
    struct tNode *var = (struct tNode *)malloc(sizeof(struct tNode));
    var->el = str[0];
    var->p = NULL;
    var->l = NULL;
    var->r = NULL;

    struct tNode *equalto = (struct tNode *)malloc(sizeof(struct tNode));
    equalto->el = '=';
    equalto->p = NULL;
    equalto->l = NULL;
    equalto->r = NULL;

    struct tNode *ptr = T->root;

    equalto->l = var;
    equalto->r = ptr;

    T->root = equalto;
    return T;
}

int main() {
    char *exp = (char *)malloc(sizeof(char)*100000);
    scanf("%s", exp);
    struct tree *T = createAssignmentTree(exp);
    inorder(T->root);
    printf("\n");
    return 0;
}

// int main() {
//     FILE *ip = fopen("input.txt", "r");
//     // FILE *op = fopen("output.txt", "w");

//     char *str = (char *)malloc(sizeof(char)*100000);
//     while(fgets(str,100000,ip) != NULL) {
//         struct tree *T = createAssignmentTree(str);
//         inorder(T->root);
//         printf("\n");
//     }
//     return 0;
// }