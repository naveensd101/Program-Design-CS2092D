#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A = (int *)malloc(0);
    int index = -1;
    char c = '1';
    char ch = '1';
    int a;
    do
    {
        scanf("%d%c", &a, &c);
        index++;
        A = (int *)realloc(A, (index + 1) * sizeof(int));
        A[index] = a;

    } while (c != '\n');

    int maxi = 0;
    int max = 0;
    int freq = 0;
    for (int i = 0; i <= index; ++i)
    {
        freq = 0;
        for (int j = 0; j < index; ++j)
        {
            if (A[i] == A[j])
                freq++;
        }
        if (freq > max)
        {
            max = freq;
            maxi = i;
        }
    }
    if (max > (index + 1) / 2)
    {
        printf("%d\n", A[maxi]);
    }
    else
    {
        printf("-1");
    }

    return 0;
}