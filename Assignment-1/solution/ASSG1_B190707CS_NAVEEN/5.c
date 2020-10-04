#include <stdio.h>
#include <stdlib.h>

int isINa(int a[], int size, int k)
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == k)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int m, n;

    scanf("%d", &m);
    int *A = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &n);
    int *B = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &B[i]);
    }

    int arr[m + n];
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        arr[i] = A[i];
    }
    count += m;
    for (int i = 0, j = m; i < n; ++i)
    {
        if (isINa(A, m, B[i]))
        {
            continue;
        }
        else
        {
            arr[j] = B[i];
            j++;
            count++;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
