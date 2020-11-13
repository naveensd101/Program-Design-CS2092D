/*Write a program to evaluate a given postfix expression. Write a function EvaluatePostfix(e),
that evaluates the given postfix expression e and returns the result of evaluation.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int a;
    struct node* next;
};
struct stack {
    struct node* head;
};
int stackEmpty(struct stack *s) {
    return (s->head == NULL ? 1 : 0);
}
struct node *createNode(int a) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->a = a;
    ptr->next = NULL;
    return ptr;
}
void push(struct stack *s, struct node *x) {
    x->next = s->head;
    s->head = x;
}
int pop(struct stack *s) {
    if(stackEmpty(s)) return '~';
    struct node *ptr = s->head;
    s->head = s->head->next;
    int a = ptr->a;
    ptr->next = NULL;
    free(ptr);
    return a;
}
int laElem(struct stack *s) {
    if(stackEmpty(s)) return 0;
    return s->head->a;
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
int calc(int a, int c, char op) {
    switch (op) {
        case '*':
        return (a*c);
        case '/':
        return (a/c);
        case '+':
        return (a+c);
        case '-':
        return (a-c);
    }
    return 0;
}

int evaluatePostfix(char *str) {
    struct stack s;
    s.head = NULL;

    for(int i = 0; str[i] != '\0'; ++i) {
        // if(str[i] == ' ') i++;
        if(isOperator(str[i])) {
            int a = pop(&s);
            int b = pop(&s);
            push(&s, createNode(calc(b, a, str[i])));
        }
        else if((int)str[i] >= (int)'0' && (int)str[i] <= (int)'9'){
            char *integer = (char *)malloc(sizeof(char)*100000);
            int in = 0;
            while(str[i] != ' ') {
                integer[in++] = str[i++];
                
            } 
            i--;
            integer[in++] = '\0';
            push(&s, createNode(atoi(integer)));
        }
    }
    return (pop(&s));
}

int main() {
    char *str = malloc(sizeof(char)*100000);
    int i = 0;
    char c;
    do {
        scanf("%c", &c);
        str[i++] = c;
    } while(c != '\n');
    str[--i] = '\0';
    printf("%d\n",evaluatePostfix(str));

    return 0;
}