#include <stdio.h>
#include <string.h>
struct worker
{
    char name[100];
    int salary;
    int work_per_day;
    int leave;
};

void INSERT(struct worker workarray[10])
{
    char name[100];
    scanf(" %[^\n]%*c", name);
    int sal = 0;
    scanf("%d", &sal);
    int workperday = 0;
    scanf("%d", &workperday);
    int leave = 0;
    scanf("%d", &leave);
    for (int i = 0; i < 10; ++i)
    {
        if (workarray[i].name[0] == '0')
        {
            strcpy(workarray[i].name, name);
            workarray[i].salary = sal;
            workarray[i].work_per_day = workperday;
            workarray[i].leave = leave;
            break;
        }
    }
}

void PRINT_NOINCREMENT(struct worker workarray[10])
{
    for (int i = 0; i < 10; ++i)
    {
        if (workarray[i].name[0] != '0')
        {
            if (workarray[i].work_per_day < 8)
            {
                printf("%s %d %d\n", workarray[i].name, workarray[i].salary, workarray[i].work_per_day);
            }
        }
    }
}

int ComputeDeductions(char ename[], struct worker workarray[10])
{
    int deduction = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (strcmp(ename, workarray[i].name) == 0)
        {
            if (workarray[i].leave > 5)
            {
                deduction = 1000 * (workarray[i].leave - 5);
                // printf("%d\n", deduction);
                break;
            }
        }
    }
    // printf("%d\n", deduction);
    return deduction;
}

void PRINT_FINALSALARY(struct worker workarray[10])
{
    for (int i = 0; i < 10; ++i)
    {
        if (workarray[i].name[0] != '0')
        {
            printf("%s ", workarray[i].name);
            if (workarray[i].work_per_day == 8)
                printf("%d ", workarray[i].salary + 50);
            else if (workarray[i].work_per_day == 10)
                printf("%d ", workarray[i].salary + 100);
            else if (workarray[i].work_per_day > 10)
                printf("%d ", workarray[i].salary + 150);
            else
                printf("%d ", workarray[i].salary);
            //printing the deduction in ther salary
            printf("%d\n", ComputeDeductions(workarray[i].name, workarray));
        }
    }
}

void PRINT_WORKPERDAY(struct worker workarray[10], int wh)
{
    for (int i = 0; i < 10; ++i)
    {
        if (workarray[i].name[0] != '0')
        {
            if (workarray[i].work_per_day == wh)
            {
                printf("%s ", workarray[i].name);
                if (workarray[i].work_per_day == 8)
                    printf("%d\n", workarray[i].salary + 50);
                else if (workarray[i].work_per_day == 10)
                    printf("%d\n", workarray[i].salary + 100);
                else if (workarray[i].work_per_day > 10)
                    printf("%d\n", workarray[i].salary + 150);
                else
                    printf("%d\n", workarray[i].salary);
            }
        }
    }
}

int main()
{
    struct worker workarray[10];
    for (int i = 0; i < 10; ++i)
    {
        workarray[i].name[0] = '0';
        workarray[i].salary = 30000;
        workarray[i].leave = 0;
    }
    while (1)
    {
        char prompt;
        scanf("%c", &prompt);
        if (prompt == 't')
            break;
        else if (prompt == 'r')
        {
            INSERT(workarray);
        }
        else if (prompt == 'i')
        {
            PRINT_NOINCREMENT(workarray);
        }
        else if (prompt == 'f')
        {
            PRINT_FINALSALARY(workarray);
        }
        else if (prompt == 'w')
        {
            int wh = 0;
            scanf("%d", &wh);
            PRINT_WORKPERDAY(workarray, wh);
        }
    }
    return 0;
}
