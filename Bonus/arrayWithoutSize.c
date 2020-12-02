/**
 * To anyone reading this, 
 * I was a bit f-ed when i was asked to handle numbers without getting size
 * Just check out this code before attending your lab test 
 * */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int main() {
    int array[100];
    int size = 0;
    char buffer[100];
    int buffersize = 0;
    while(1) {
        char c;
        scanf("%c", &c);

        if(c == '\n') {
            if(buffersize == 0) {
                break;
            }
            array[size++] = atoi(buffer);
            buffersize = 0;
            break;
        }
        else if(c == ' ') {
            array[size++] = atoi(buffer);
            buffersize = 0;
        }
        else {
            buffer[buffersize++] = c;
            buffer[buffersize] = '\0';
        }
    }
    printf("size: %d\n", size);
    for(int i = 0; i < size; ++i) printf("%d ",  array[i]);
    printf("\n");
    return 0;
}