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
    int a[] = {1, 2, 3, 4, 5};
    array testarray;
    testarray.ptr = a;
    testarray.length = sizeof(a) / sizeof(int);
    testarray.type = INT;

    printf("Testing the array:\n");
    for (int *i = testarray.ptr; i < (int *)testarray.ptr + testarray.length; i++)
    {
        printf("%d ", *i);
    }

    printf("\nReversing the array:\n");
    areverse(&testarray);
    for (int i = 0; i < testarray.length; i++)
    {
        printf("%d ", a[i]);
    }

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

    lreverse(testlist);
    printf("\nReversing the list:\n");
    for (int i = 0; i < llength(testlist); i++)
    {
        printf("%lf ", lvalue(testlist, i));
    }
    printf("\nContent examination: 35?: %d, 49?: %d\n", lcontains(testlist, 35), lcontains(testlist, 49));

    return 0;
}

int mathfunctions()
{
    printf("5th root of 248832:\n%lf\n", root(248832, 5));

    return 0;
}