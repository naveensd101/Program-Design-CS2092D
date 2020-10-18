#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct counter
{
    float *array_rtime;
    char arry_bno[1000][50];
    int n;
};

//r
void read_details(struct counter *c, int n)
{
    (*c).n = n;
    (*c).array_rtime = (float *)malloc(n * sizeof(float));
    char bno[50];
    float rtime;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s %f", bno, &rtime);
        (*c).array_rtime[i] = rtime;
        strcpy((*c).arry_bno[i], bno);
    }
}

//p
void peak_time(struct counter c, int n)
{
    int count = 0;
    float prev = 0;

    float peaktime = 0;
    int peakcount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (prev == c.array_rtime[i])
        {
            count++;
        }
        if (prev != c.array_rtime[i])
        {
            count = 1;
            prev = c.array_rtime[i];
        }
        if (peakcount < count)
        {
            peakcount = count;
            peaktime = c.array_rtime[i];
        }
    }
    printf("%.2f\n", peaktime);
}

//d
void display_details(struct counter c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%s %.2f\n", c.arry_bno[i], c.array_rtime[i]);
    }
}

//g
void group_k(struct counter c1, struct counter c2, struct counter c3, int n, int k)
{
    int it1 = 0, it2 = 0, it3 = 0;
    float prev = -1.0;
    for (int groupcount = 0; groupcount < k || (prev == c3.array_rtime[it3] || prev == c2.array_rtime[it2] || prev == c1.array_rtime[it1]);)
    {

        // float smallest = c1.array_rtime[(it1)];
        float smallest = 9999999.9;
        if (it1 <= n && smallest > c1.array_rtime[it1])
        {
            smallest = c1.array_rtime[it1];
        }
        if (it2 <= n && smallest > c2.array_rtime[it2])
        {
            smallest = c2.array_rtime[it2];
        }
        if (it3 <= n && smallest > c3.array_rtime[it3])
        {
            smallest = c3.array_rtime[it3];
        }
        if (smallest != prev)
        {
            // printf("%d %d %d\n", it1, it2, it3);
            groupcount++;
        }
        prev = smallest;
        if (it1 <= n && fabs(smallest - c1.array_rtime[it1]) < 0.001)
        {
            printf("%s %.2f\n", c1.arry_bno[it1], c1.array_rtime[it1]);
            it1++;
        }
        if (it2 <= n && fabs(smallest - c2.array_rtime[it2]) < 0.001)
        {
            printf("%s %.2f\n", c2.arry_bno[it2], c2.array_rtime[it2]);
            it2++;
        }
        if (it3 <= n && fabs(smallest - c3.array_rtime[it3]) < 0.001)
        {
            printf("%s %.2f\n", c3.arry_bno[it3], c3.array_rtime[it3]);
            it3++;
        }
        // printf("%d %d %d %d\n", it1, it2, it3, groupcount);
    }
}

int main()
{
    struct counter c1, c2, c3;
    char c = 'r';
    int n;
    scanf("%d\n", &n);
    while (c != 't')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'r':
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
                read_details(&c1, n);
            else if (a == 2)
                read_details(&c2, n);
            else if (a == 3)
                read_details(&c3, n);
            break;
        }

        case 'p':
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
                peak_time(c1, n);
            else if (a == 2)
                peak_time(c2, n);
            else if (a == 3)
                peak_time(c3, n);
            break;
        }

        case 'd':
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
                display_details(c1, n);
            else if (a == 2)
                display_details(c2, n);
            else if (a == 3)
                display_details(c3, n);
            break;
        }

        case 'g':
        {
            int k;
            scanf("%d", &k);
            group_k(c1, c2, c3, n, k);
            break;
        }

        default:
            break;
        }
    }
    return 0;
}