#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

struct pq
{
    int *arr;
    int N;
    int heapsize;
};

void MinHeapify(struct pq *q, int i)
{
    i++;
    int left = 2 * i;
    left--;
    int right = 2 * i + 1;
    right--;
    i--;

    int smallest = INT_MAX;
    if (left < (*q).heapsize && (*q).arr[i] > (*q).arr[left])
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if (right < (*q).heapsize && (*q).arr[smallest] > (*q).arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        // swap (i, smallest)
        int temp = (*q).arr[i];
        (*q).arr[i] = (*q).arr[smallest];
        (*q).arr[smallest] = temp;
        MinHeapify(q, smallest);
    }
}
int parent(int i)
{
    i++;
    int temp = i / 2;
    temp--;
    return temp;
}
//c
void HeapDecKey(struct pq *q, int i, int val)
{
    if ((*q).arr[i] < val)
        return;
    (*q).arr[i] = val;
    while (i >= 0 && (*q).arr[i] < (*q).arr[parent(i)])
    {
        int temp = (*q).arr[i];
        (*q).arr[i] = (*q).arr[parent(i)];
        (*q).arr[parent(i)] = temp;
        i = parent(i);
    }
}

//i
void InsertPatient(int a, struct pq *q)
{
    (*q).N++;
    (*q).arr = (int *)realloc((*q).arr, sizeof(int) * ((*q).N));
    (*q).heapsize++;
    (*q).arr[(*q).heapsize - 1] = INT_MAX;
    HeapDecKey(q, (*q).heapsize - 1, a);
}

//e
int ExtractNextPatient(struct pq *q)
{
    if ((*q).heapsize < 1)
    {
        return -1;
    }
    int remval = (*q).arr[0];
    (*q).arr[0] = (*q).arr[(*q).heapsize - 1];
    (*q).heapsize--;
    (*q).N--;
    return remval;
}

//m
int GetNextPatient(struct pq *q)
{
    if ((*q).heapsize < 1)
    {
        return -1;
    }
    return (*q).arr[0];
}

void BuildMinHeap(struct pq *q)
{
    (*q).heapsize = (*q).N;
    for (int i = (*q).heapsize / 2; i >= 0; i--)
    {
        MinHeapify(q, i);
    }
}

void Heapsort(struct pq *q)
{
    BuildMinHeap(q);
    for (int i = (*q).N - 1; i >= 1; --i)
    {
        //swap(a[i], a[0])
        int temp = (*q).arr[i];
        (*q).arr[i] = (*q).arr[0];
        (*q).arr[0] = temp;

        (*q).heapsize--;
        MinHeapify(q, 0);
    }
}

//d
void DisplayQ(struct pq qog)
{
    struct pq q;
    q.N = qog.N;
    q.heapsize = qog.heapsize;
    q.arr = (int *)malloc(sizeof(int) * q.N);
    for (int i = 0; i < q.N; ++i)
        q.arr[i] = qog.arr[i];
    assert(&q != NULL);
    Heapsort(&q);
    for (int i = q.N - 1; i >= 0; i--)
        printf("%d ", q.arr[i]);
    printf("\n");
}

int main()
{
    struct pq Q;
    Q.N = 0;
    Q.heapsize = 0;
    Q.arr = (int *)malloc(0 * sizeof(int));

    char c = 'a';
    while (c != 's')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
        {
            int val;
            scanf("%d", &val);
            InsertPatient(val, &Q);
            break;
        }

        case 'e':
        {
            printf("%d\n", ExtractNextPatient(&Q));
            break;
        }

        case 'm':
        {
            printf("%d\n", GetNextPatient(&Q));
            break;
        }

        case 'c':
        {
            int old, new;
            scanf("%d %d", &old, &new);
            for (int i = 0; i < Q.heapsize; ++i)
            {
                if (old == Q.arr[i])
                    old = i;
            }

            HeapDecKey(&Q, old, new);
            break;
        }

        case 'd':
        {
            DisplayQ(Q);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
