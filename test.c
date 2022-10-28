#include <stdio.h>
#include <time.h>
#include "cleanc.h"

int iofunctions();
int variablefunctions();
int arrayfunctions();
int listfunctions();
int mathfunctions();

int main()
{
    // iofunctions();
    // variablefunctions();
    // arrayfunctions();
    // listfunctions();
    // mathfunctions();
}

int iofunctions()
{
    printf("Flushing the input buffer:\n");
    scanvoid();

    return 0;
}

int variablefunctions()
{
    double a = 24.532;
    double b = 55325.43;

    printf("Variables:\na: %lf, b: %lf", a, b);
    
    swap(&a, &b, DOUBLE);
    printf("\nSwapping variables:\na: %lf, b: %lf\n", a, b);

    return 0;
}

int arrayfunctions()
{
    int a[] = {3, 2, 5, 1, 4};

    printf("Testing the array:\n");
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }


    printf("\nSort the array in ascending order:\n");
    asort(&a[0], &a[4], INT);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nReversing the array:\n");
    areverse(&a[0], &a[4], INT);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nContent examination: 4?: %d, 7?: %d\n", acontint(&a[0], &a[4], 4, INT), acontint(&a[0], &a[4], 7, INT));

    char intstring[] = "34543";
    printf("\nConverting string(34543) to int: %d\n", strint(intstring));
    char doublestring[] = "876.564";
    printf("Converting double(876.564) to double: %lf\n", strdouble(doublestring));
    char falseintstring[] = "432.46";
    printf("Converting double(432.46) to int: %d\n", strint(falseintstring));

    return 0;
}

int listfunctions()
{
    list *testlist = NULL;

    for (int i = 30; i < 45; i++)
    {
        ladd(&testlist, i);
    }
    printf("Filling the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }

    lchange(testlist, 12, 50);
    printf("\nChanging a value in the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }

    lremove(&testlist, 10);
    printf("\nRemoving a value from the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }

    linsert(testlist, 5, 78);
    printf("\nInserting a value into the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }

    lreverse(testlist, 0, llength(testlist) - 1);
    printf("\nReversing the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }
    printf("\nContent examination: 35?: %d, 49?: %d\n", lcontains(testlist, 0, llength(testlist) - 1, 35), lcontains(testlist, 0, llength(testlist) - 1, 49));

    return 0;
}

int mathfunctions()
{
    printf("10 Random number in [8; 12] interval:\n");
    randinit();
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", random(8, 12));
    }
    printf("\n5th root of 248832:\n%lf\n", root(248832, 5));

    return 0;
}