#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertBefore(float l1[], float toput, int myelem_index, int n1)
{
    for (int i = (n1)-1; i >= myelem_index; i--)
    {
        l1[i + 1] = l1[i];
    }
    l1[myelem_index] = toput;
    // (*n1)++;
}
void combine(float l1[], float l2[], int n1, int n2)
{
    int j = 0;
    int i = 0;
    for (i = 0, j = 0; i < n1 + n2;)
    {
        // printf("%d\n", i);
        if(l1[i] == -1)
        {
            insertBefore(l1,l2[j],i, n1+n2);
            j++;
            i++;
        }
        else if(l2[j]== -1)
        {
            i++;
        }
        else if(l1[i] > l2[j])
        {
            insertBefore(l1,l2[j],i,n1+n2);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    // printf("%d\n", j);
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    float *l1, *l2;
    l1 = (float *)malloc(50 * sizeof(float));
    l2 = (float *)malloc(50 * sizeof(float));
    for (int i = 0; i < 50; ++i)
    {
        l1[i] = -1.0;
        l2[i] = -1.0;
    }
    for (int i = 0; i < n1; ++i)
        scanf("%f", &l1[i]);
    for (int i = 0; i < n2; ++i)
        scanf("%f", &l2[i]);
    // assert(l1[6]);
    // printf("%f\n", l1[6]);
    // printf("%d\n", n1);
    combine(l1, l2, n1, n2);
    // printf("%d\n", n1);
    for (int i = 0; i < n1 + n2; ++i)
    {
        printf("%.2f ", l1[i]);
    }
    return 0;
}