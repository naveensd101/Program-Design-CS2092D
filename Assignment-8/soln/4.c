/*Write a menu driven program for the evaluation of multiple postfixx expressions. Input should be
read from the file input.txt and output should be written to the file output.txt. Your program
should include the following functions.
• Main() reads each line of the file input.txt and calls the function evaluatePostfix(e) until
end-of-file is reached.
• evaluatePostfix(e) evaluate the given postfix expression e and print the result.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

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
int notnum(char c) {
    if(c < '0' && c > '9') return 1;
    return 0;
}
int evaluatePostfix(char *str) {
    struct stack s;
    s.head = NULL;

    for(int i = 0; str[i] != '\0'&&str[i]!='\n'; ++i) {
        // if(str[i] == ' ') i++;
        assert(str[i]);
        if(isOperator(str[i])&&(i==(strlen(str)-1) || str[i+1] == ' ')) {
            // printf("c:%c %d\n", str[i+1], notnum(str[i+1]));
            int a = pop(&s);
            int b = pop(&s);
            // printf("%d, %d, %d\n",b, a, calc(b, a, str[i]));
            push(&s, createNode(calc(b, a, str[i])));
        }
        else if(((int)str[i] >= (int)'0' && (int)str[i] <= (int)'9') || str[i] == '-'){
            int isneg = 0;
            if(str[i] == '-') {
                isneg = 1;
                i++;
            }
            char *integer = (char *)malloc(sizeof(char)*100000);
            int in = 0;
            while(str[i] != ' ') {
                integer[in++] = str[i++];
                
            } 
            i--;
            integer[in++] = '\0';
            // printf("%d: ", isneg);
            // printf("%d\n", (isneg?-1*atoi(integer):atoi(integer)));
            if(isneg) push(&s, createNode(-1*atoi(integer)));
            else push(&s, createNode(atoi(integer)));
        }
    }
    return (pop(&s));
}

void submain() {
    FILE *ip = fopen("input.txt", "r");
    char *str = malloc(sizeof(char)*100000);
    // fgets(str, 100000, stdin);
    int i = 0;
    char c;
    do {
        scanf("%c", &c);
        str[i++] = c;
    } while(c != '\n');
    str[--i] = '\0';
    printf("%s\n", str);
    // printf("%d\n",evaluatePostfix(str));

    // return 0;
}

int main() {
    // submain();
    // return 0;
    FILE *ip = fopen("input.txt", "r");
    FILE *op = fopen("output.txt", "w");

    char *str = (char *)malloc(sizeof(char)*100000);
    while(fgets(str, 100000, ip) != NULL) {
        // printf("%c", str[strlen(str)-3]);
        str[strlen(str)-2] = '\0';
        fprintf(op, "%d\n", evaluatePostfix(str));
    }

    fclose(ip);
    fclose(op);
    return 0;
}

