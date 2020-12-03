#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer {
    int acc_no;
    char cust_name[100];
    float balance;
    int length;
};

void read_and_store(struct customer C[], int n) {
    for(int i = 0; i < n; ++i) {
        int ano;
        char name[100];
        float bal;
        scanf("%d %s %f", &ano, name, &bal);
        C[i].acc_no = ano;
        C[i].balance = bal;
        strcpy(C[i].cust_name, name);
        C[i].length = n;
    }
}
void display(struct customer C[], int n) {
    for(int i = 0; i < n; ++i) {
        printf("%d %s %.2f\n", C[i].acc_no, C[i].cust_name, C[i].balance);
    }
}
void sort_records(struct customer C[], int n) {
    int key, i;
    struct customer copy;
    for(int j = 1; j < n; ++j) {
        key = C[j].acc_no;
        copy = C[j];
        i = j - 1;
        while(i >= 0 && C[i].acc_no > key) {
            C[i+1] = C[i];
            i--;
        }
        C[i+1] = copy;
    }
}
void search_record(struct customer C[], int a) {
    int n = C[0].length;
    for(int i = 0; i < n; ++i) {
        if(C[i].acc_no == a) {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int canwe = 1;
    struct customer C[100];
    int n;
    while(canwe) {
        char c;
        scanf("%c", &c);
        switch (c) {
            case 'r': {
                scanf("%d", &n);
                read_and_store(C, n);
                break;
            }
            case 's': {
                sort_records(C, n);
                break;
            }
            case 'f': {
                int a;
                scanf("%d", &a);
                search_record(C, a);
                break;
            }
            case 'd': {
                display(C, n);
                break;
            }
            case 'e': {
                canwe = 0;
                break;
            }
        }
    }
    return 0;
}