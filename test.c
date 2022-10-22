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
    char a[] = "doman";
    array tomb;
    tomb.ptr = a;
    tomb.length = 5;
    tomb.type = CHAR;

    areverse(&tomb, tomb.type);

    for (char *i = tomb.ptr; i < (char *)tomb.ptr + tomb.length; i++)
    {
        printf("%c", *i);
    }
    printf("\n");
    

    return 0;
}