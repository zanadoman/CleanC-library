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
    list *lista = NULL;

    for (int i = 0; i < 25; i++)
    {
        ladd(&lista, i);
    }

    lremove(&lista, 24);
    lremove(&lista, 0);
    lreverse(lista);
    linsert(lista, 0, 69);
    ladd(&lista, 69);
    lreverse(lista);

    printlist(lista);

    return 0;
}