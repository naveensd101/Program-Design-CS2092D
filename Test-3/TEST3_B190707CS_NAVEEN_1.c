#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct pcb {
    int process_id;
    char priority[100];
    struct pcb *next;
};

struct list {
    struct pcb *head;
    struct pcb *tail;
};


int listEmpty (struct list *l) {
    return (l->head == NULL && l->tail == NULL ? 1: 0);
}

struct pcb * createPCB(int k, char str[]) {
    struct pcb *newNode = (struct pcb *)malloc(sizeof(struct pcb));
    newNode->next = NULL;
    newNode->process_id = k;
    strcpy(newNode->priority, str);

    return newNode;
}
void insertEnd(struct list *q, struct pcb *x) {
    if (listEmpty(q))
    {
        q->head = x;
        q->tail = x;
    }
    else
    {
        q->tail->next = x;
        q->tail = x;
    }
}

void listProcess (struct list *l) {
    struct pcb *ptr = l->head;
    if(ptr == NULL) {
        printf("-1\n");
        return;
    }
    while(ptr!=NULL) {
        if(ptr->process_id>0)("%d ", ptr->process_id);
        ptr=ptr->next;
    }
    return;
}
void moveToR(struct pcb *p, struct list *R) {
    if(strcmp(p->priority,"high") == 0)
    {
        if(listEmpty(R))
        {
            R->head = p;
            R->tail = p;
        }
        else
        {
            struct pcb *ptr = R->head;
            while(ptr!=NULL) {
                if(strcmp(ptr->priority,"high")==0&&(ptr->next == NULL || strcmp(ptr->next->priority,"med")))
                {
                    p->next = ptr->next;
                    ptr->next = p;
                    break;
                }
                ptr = ptr->next;
            }
        }
        
    }
}
void schedule(struct pcb *p, struct list *R) {
    if(listEmpty(R)) {
        printf("-1");
        return;
    }
    if(p==NULL) {
        p = R->head;
        R->head = R->head->next;
    }
    if(p!=NULL) {
        moveToR(p, R);
        p = R->head;
        R->head = R->head->next;
    }

}
void updateState(int k, struct list *L1, struct list *L2) {
    struct pcb * ptr = L1 ->head;
    while(ptr!=NULL) {
        if(ptr->process_id == k) {
            moveToR(ptr,L2);
            ptr->process_id = 0;
            strcpy(ptr->priority, "NA");
            break;
        }
        ptr = ptr->next;
    }
}

int main() {
    struct list *N = (struct list *)malloc(sizeof(struct list));
    N->head = NULL;
    N->tail = NULL;
    struct list *R = (struct list *)malloc(sizeof(struct list));
    R->head = NULL;
    R->tail = NULL;
    struct list *W = (struct list *)malloc(sizeof(struct list));
    W->head = NULL;
    W->tail = NULL;
    struct list *T = (struct list *)malloc(sizeof(struct list));
    T->head = NULL;
    T->tail = NULL;

    struct pcb *running; //= (struct pcb *)malloc(sizeof(struct pcb));
    running = NULL;

    int id_array[100];
    for(int i = 0; i < 100; ++i) id_array[i] = 0;

    int canwe = 1;
    while(canwe)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'c':
        {
            char str[100];
            scanf("%s", str);
            int id;
            for(int i = 0; i < 100; ++i) {
                if(id_array[i]==0) {
                    id_array[i] = 1;
                    id = i+1;
                    break;
                }
            }
            insertEnd(N, createPCB(id, str));
            break;
        }
        case 'l':
        {
            int disp;
            scanf("%d", &disp);
            if(disp == 1) 
            {
                // printf("hi");
                struct pcb *ptr = N->head;
                while(ptr!=NULL){
                    printf("%d ", ptr->process_id);
                    ptr = ptr->next;
                }
                printf("\n");
                // listProcess(N);
            }
            if(disp == 2) 
            {
                listProcess(R);
            }
            if(disp == 3) 
            {
                listProcess(W);
            }
            if(disp == 4) 
            {
                listProcess(T);
            }
            break;
        }
        case 'u':
        {
            int k;
            char s1[100], s2[100];
            scanf("%d %s %s", &k, s1, s2);
            if(strcmp(s1,"running")==0&&strcmp(s2,"waiting"))
            {
                insertEnd(W,running);
                schedule(running, R);
            }
            else
            {
                if(strcmp(s1,"new")==0&&strcmp(s2,"ready"))
                {
                    updateState(k,N,R);
                }
                if(strcmp(s1,"waiting")==0&&strcmp(s2,"ready"))
                {
                    updateState(k,W,R);
                }
            }
            
            break;
        }
        case 's':
        {
            schedule(running, R);
            break;
        }
        case 't':
        {
            printf("%d\n", running->process_id);
            schedule(running, R);
            break;
        }
        case 'e':
        {
            canwe = 0;
            break;
        }
        
        default:
            break;
        }
    }



    return 0;
}