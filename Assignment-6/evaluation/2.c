#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct stu
{
    char name[50];
    float cgpa;
};
void insertBefore(struct stu l1[], struct stu toput, int myelem_index, int n1)
{
    for(int i = n1-1; i >= myelem_index; i--)
    {
        l1[i+1].cgpa = l1[i].cgpa;
        strcpy(l1[i+1].name, l1[i].name);
    }
    l1[myelem_index].cgpa = toput.cgpa;
    strcpy(l1[myelem_index].name, toput.name);
}
void combine(struct stu l1[], struct stu l2[], int n1, int n2)
{
    int i = 0, j = 0;
    for(i = 0, j= 0; i < n1+n2;)
    {
        if(l1[i].cgpa == -1)
        {
            insertBefore(l1,l2[j],i,n1+n2);
            j++;
            i++;
        }
        else if(l2[j].cgpa == -1)
        {
            i++;
        }
        else if(l1[i].cgpa > l2[j].cgpa)
        {
            insertBefore(l1,l2[j],i,n1+n2);
            i++;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{
    struct stu l1[50];
    struct stu l2[50];
    for(int i = 0; i < 50; ++i)
    {
        l1[i].cgpa = -1.0;
        strcpy(l1[i].name,"nill");
        l2[i].cgpa = -1.0;
        strcpy(l2[i].name, "nill");
    }
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    for(int i = 0; i < n1; ++i)
    {
        char name[50];
        float cgpa;
        scanf("%s %f", name, &cgpa);
        l1[i].cgpa = cgpa;
        strcpy(l1[i].name, name);
    }
    for(int j = 0; j < n2; ++j)
    {
        char name[50];
        float cgpa;
        scanf("%s %f", name, &cgpa);
        l2[j].cgpa = cgpa;
        strcpy(l2[j].name, name); 
    }
    combine(l1, l2, n1, n2);
    for(int i = 0; i < n1+n2; ++i)
    {
        printf("%s %.2f\n", l1[i].name, l1[i].cgpa);
    }
    return 0;
}