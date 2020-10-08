#include <stdio.h>
#include <limits.h>
#include <math.h>
struct heap
{
    int arr[1000001];
    int heapsize;
    int length;
};

int parent(int i)
{
    i++;
    return (floor(i / 2) - 1); //floor(i/2)
}
int left(int i)
{
    i++;
    return 2 * i - 1; //2*i
}
int right(int i)
{
    i++;
    return 2 * i; //2*i+1
}

void Min_heapify(struct heap *A, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest;

    if (l <= (*A).heapsize && (*A).arr[l] < (*A).arr[i])
        smallest = l;
    else
        smallest = i;
    if (r <= (*A).heapsize && (*A).arr[r] < (*A).arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        int temp = (*A).arr[i];
        (*A).arr[i] = (*A).arr[smallest];
        (*A).arr[smallest] = temp;

        Min_heapify(A, smallest);
    }
}

int Heap_min(struct heap *A)
{
    if ((*A).heapsize < 1)
    {
        // printf("\nerror\n");
        return -1;
    }
    return (*A).arr[0];
}

int Heap_extract_min(struct heap *A)
{
    if ((*A).heapsize < 1)
    {
        // printf("\nerror\n");
        return -1;
    }
    int min = (*A).arr[0];
    (*A).arr[0] = (*A).arr[(*A).heapsize - 1];
    (*A).heapsize--;
    Min_heapify(A, 0);
    return min;
}

void Heap_decrease_key(struct heap *A, int i, int key)
{
    if (key > (*A).arr[i])
    {
        // printf("\nerror\n");
        return;
    }
    (*A).arr[i] = key;
    while (i > 0 && (*A).arr[parent(i)] > (*A).arr[i])
    {
        int temp = (*A).arr[i];
        (*A).arr[i] = (*A).arr[parent(i)];
        (*A).arr[parent(i)] = temp;

        i = parent(i);
    }
}

void Min_heap_insert(struct heap *A, int key)
{
    (*A).heapsize++;
    (*A).arr[A->heapsize - 1] = INT_MAX;
    Heap_decrease_key(A, (*A).heapsize - 1, key);
}

int main()
{
    struct heap A;
    A.arr[0] = -1;
    A.heapsize = 0;
    A.length = 0;
    while (1)
    {
        char c;
        scanf("%c", &c);

        if (c == 's')
            break;

        switch (c)
        {
        case 'i':
        {
            int temp = 0;
            scanf("%d", &temp);
            Min_heap_insert(&A, temp);
            break;
        }
        case 'e':
        {
            printf("%d\n", Heap_extract_min(&A));
            break;
        }
        case 'm':
        {
            printf("%d\n", Heap_min(&A));
            break;
        }
        case 'd':
        {
            int i, k;
            scanf("%d %d", &i, &k);
            Heap_decrease_key(&A, i, k);
            break;
        }
        }
    }
    return 0;
}