#include <stdio.h>
#include <math.h>

struct heap
{
    long arr[100007];
    int heapsize;
    int length;
};

int Max_heapify(struct heap *h, int i)
{

    int count = 0;
    int l = 2 * (i+1);
    int r = l + 1;
    l--;r--;

    int largest = 0;

    if (l < h->heapsize && (++count ? 1 : 1) && h->arr[l] > h->arr[i])
        largest = l;
    else
        largest = i;
    if (r < h->heapsize && (++count ? 1 : 1) && h->arr[r] > h->arr[largest])
        largest = r;

    if (largest != i)
    {
        //swap
        int temp = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = temp;

        count += Max_heapify(h, largest);
    }
    return count;
}

int Build_max_heap(struct heap *h)
{
    int count = 0;
    h->heapsize = h->length;
    for (int i = floor(h->length / 2) - 1; i >= 0; --i)
        count += Max_heapify(h, i);
    return count;
}

int Heap_sort(struct heap *h)
{
    int count = 0;
    count+= Build_max_heap(h);
    for (int i = h->length - 1; i > 0; i--)
    {
        //swap
        int temp = h->arr[i];
        h->arr[i] = h->arr[0];
        h->arr[0] = temp;

        h->heapsize--;
        count += Max_heapify(h, 0);
    }
    return count;
}

int main()
{
    struct heap h;

    scanf("%d", &(h.length));
    for (int i = 0; i < h.length; ++i)
        scanf("%ld", &h.arr[i]);

    int count = 0;
    count = Heap_sort(&h);

    for (int i = 0; i < h.length; ++i)
        printf("%ld ", h.arr[i]);
    printf("\n%d\n", count);
    return 0;
}
