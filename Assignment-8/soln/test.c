#include<stdio.h>
#include<stdlib.h>

void pri(char *str) {
    for(int i = 0; str[i] != '\0'; ++i) {
        printf("%c", str[i]);
    }
}
int main() {
    char str[] = "hi + - ++";
    pri(str);
    return 0;
}