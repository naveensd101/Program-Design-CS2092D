/*Write a program for converting a given infix expression to postfix form using STACK. Write a
function InfixToPostfix(e) which converts the given infix expression e to postx expression and
returns the postx expression.
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
    char c;
    struct node *next;
};
struct stack {
    struct node *head;
};
int stackEmpty(struct stack *s) {
    return (s->head == NULL ? 1 : 0);
}
struct node *createNode(char c) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->c = c;
    ptr->next = NULL;
    return ptr;
}
void push(struct stack *s, struct node *x) {
    x->next = s->head;
    s->head = x;
}
char pop(struct stack *s) {
    if(stackEmpty(s)) {
        return '~';
    }
    struct node *ptr = s->head;
    s->head=s->head->next;
    char c = ptr->c;
    ptr->next = NULL;
    free(ptr);
    return c;
}
char laElem(struct stack *s) {
    if(stackEmpty(s)) return '#';
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
    struct stack s;
    s.head = NULL;
    char *res = (char*)malloc(sizeof(char)*100000);
    int resptr = 0;
    
    for(int i = 0; str[i] != '\0'; ++i) {
        if(((int)str[i]>=(int)'a' && (int)str[i]<=(int)'z') || ((int)str[i]>='A' && (int)str[i]<='Z')) 
            res[resptr++] = str[i];
        else if(str[i] == ')') {
            while(laElem(&s) != '('){
                char y = pop(&s);
                res[resptr++] = y;
            }
            pop(&s);
        }
        else {
            char y = laElem(&s);
            if(icp(str[i]) > isp(y)) {
                push(&s, createNode(str[i]));
            }
            else {
                while(stackEmpty(&s) == 0 && isp(laElem(&s)) >= icp(str[i])) {
                    res[resptr++] = pop(&s);
                }
                push(&s, createNode(str[i]));
            }
        }
    }
    while(stackEmpty(&s) == 0) {
        res[resptr++] = pop(&s);
    }

    return res;
}

int main() {
    char str[100000];
    scanf("%s", str);
    printf("%s\n", infixToPostfix(str));
    return 0;
}