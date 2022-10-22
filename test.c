#include <stdio.h>
#include "cleanc.h"

int printlist(list *head);

int printlist(list *head)
{
    for (int i = 0; i < llength(head); i++)
    {
        printf("%lf ", lvalue(head, i));
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    array tomb;
    tomb.ptr = a;
    tomb.length = 7;
    tomb.type = INT;

    areverse(&tomb);

    for (int *i = tomb.ptr; i < (int *)tomb.ptr + tomb.length; i++)
    {
        printf("%d ", *i);
    }
    

    return 0;
}