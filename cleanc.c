/* CleanC.h - 2022Q4 - Version beta
Developed by: Doman Zana, for the sake of humanity
and to make C a clean and modern programming language. */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Bool definition
#define true 1
#define false 0
typedef char bool;

// Array definition
struct arrayDef
{
    void *ptr;
    char type;
    int length;
};
typedef struct arrayDef array;

// List definition
struct listNode
{
    double lValue;
    struct listNode *lNext;
    struct listNode *lPrev;
};
typedef struct listNode list;

int swapmChar(void *a, void *b);
int swapmShort(void *a, void *b);
int swapmInt(void *a, void *b);
int swapmLong(void *a, void *b);
int swapmFloat(void *a, void *b);
int swapmDouble(void *a, void *b);

// IO functions
long scanint()
{
    long input;
    char correct, empty;
    do
    {
        correct = 0;
        if (scanf("%ld", &input) != 1)
        {
            correct = 1;
            while ((empty = getchar()) != '\n')
                ;
        }
    } while (correct);
    return input;
}
double scandouble()
{
    double input;
    char correct, empty;
    do
    {
        correct = 0;
        if (scanf("%lf", &input) != 1)
        {
            correct = 1;
            while ((empty = getchar()) != '\n')
                ;
        }
    } while (correct);
    return input;
}
int scanvoid()
{
    while (getchar() != '\n')
        ;
    return 0;
}

// Array functions
int areverse(array *a)
{
    for (int *i = a->ptr, j = 1; i < (int *)a->ptr + a->length / 2; i++, j++)
    {
        *i += *((int *)a->ptr + a->length - j);
        *((int *)a->ptr + a->length- j) = *i - *((int *)a->ptr + a->length - j);
        *i = *i - *((int *)a->ptr + a->length - j);
    }
    return 0;
}

// Variable functions
int swapc(void *a, void *b, char size)
{
    switch (size)
    {
    case 1:
        *(char *)a += *(char *)b;
        *(char *)b = *(char *)a - *(char *)b;
        *(char *)a = *(char *)a - *(char *)b;
        break;
    case 2:
        *(short *)a += *(short *)b;
        *(short *)b = *(short *)a - *(short *)b;
        *(short *)a = *(short *)a - *(short *)b;
        break;
    case 4:
        *(int *)a += *(int *)b;
        *(int *)b = *(int *)a - *(int *)b;
        *(int *)a = *(int *)a - *(int *)b;
        break;
    case 8:
        *(double *)a += *(double *)b;
        *(double *)b = *(double *)a - *(double *)b;
        *(double *)a = *(double *)a - *(double *)b;
        break;
    }
    return 0;
}
int swapm(void *a, void *b, char size)
{
    switch (size)
    {
    case 1:
        swapmChar(a, b);
        break;
    case 2:
        swapmShort(a, b);
        break;
    case 3:
        swapmInt(a, b);
        break;
    case 4:
        swapmLong(a, b);
        break;
    case 5:
        swapmFloat(a, b);
        break;
    case 6:
        swapmDouble(a, b);
        break;
    }
    return 0;
}
int swapmChar(void *a, void *b)
{
    char temp = *(char *)a;
    *(char *)a = *(char *)b;
    *(char *)b = temp;
    return 0;
}
int swapmShort(void *a, void *b)
{
    short temp = *(short *)a;
    *(short *)a = *(short *)b;
    *(short *)b = temp;
    return 0;
}
int swapmInt(void *a, void *b)
{
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
    return 0;
}
int swapmLong(void *a, void *b)
{
    long temp = *(long *)a;
    *(long *)a = *(long *)b;
    *(long *)b = temp;
    return 0;
}
int swapmFloat(void *a, void *b)
{
    float temp = *(float *)a;
    *(float *)a = *(float *)b;
    *(float *)b = temp;
    return 0;
}
int swapmDouble(void *a, void *b)
{
    double temp = *(double *)a;
    *(double *)a = *(double *)b;
    *(double *)b = temp;
    return 0;
}

// List functions
int ladd(list **listptr, double value)
{
    list *nodeNew = malloc(sizeof(struct listNode));
    nodeNew->lValue = value;
    nodeNew->lNext = NULL;
    nodeNew->lPrev = NULL;
    nodeNew->lNext = *listptr;
    if (*listptr != NULL)
    {
        (*listptr)->lPrev = nodeNew;
    }
    *listptr = nodeNew;
    nodeNew->lPrev = NULL;
    return 0;
}
int linsert(list *listptr, int index, double value)
{
    list *nodeInsertAfter = listptr;
    while (nodeInsertAfter->lNext != NULL)
    {
        nodeInsertAfter = nodeInsertAfter->lNext;
    }
    for (int i = 0; i < index; i++)
    {
        nodeInsertAfter = nodeInsertAfter->lPrev;
    }
    list *nodeNew = malloc(sizeof(struct listNode));
    nodeNew->lValue = value;
    nodeNew->lNext = NULL;
    nodeNew->lPrev = NULL;
    if (nodeInsertAfter->lNext == NULL)
    {
        nodeNew->lPrev = nodeInsertAfter;
        nodeNew->lNext = NULL;
        nodeInsertAfter->lNext = nodeNew;
    }
    else
    {
        nodeNew->lPrev = nodeInsertAfter;
        nodeNew->lNext = nodeInsertAfter->lNext;
        nodeInsertAfter->lNext = nodeNew;
        nodeNew->lNext->lPrev = nodeNew;
    }
}
int lremove(list **listptr, int index)
{
    list *nodeToRemove = *listptr;
    while (nodeToRemove->lNext != NULL)
    {
        nodeToRemove = nodeToRemove->lNext;
    }
    for (int i = 0; i < index; i++)
    {
        nodeToRemove = nodeToRemove->lPrev;
    }
    if (nodeToRemove->lPrev != NULL)
    {
        nodeToRemove->lPrev->lNext = nodeToRemove->lNext;
    }
    if (nodeToRemove->lNext != NULL)
    {
        nodeToRemove->lNext->lPrev = nodeToRemove->lPrev;
    }
    if (nodeToRemove == *listptr)
    {
        *listptr = nodeToRemove->lNext;
    }
    nodeToRemove->lPrev = nodeToRemove->lNext = NULL;
    return 0;
}
double lvalue(list *listptr, int index)
{
    list *temp = listptr;
    while (temp->lNext != NULL)
    {
        temp = temp->lNext;
    }
    for (int i = 0; i < index; i++)
    {
        temp = temp->lPrev;
    }
    return temp->lValue;
}
int lchange(list *listptr, int index, int value)
{
    list *temp = listptr;
    while (temp->lNext != NULL)
    {
        temp = temp->lNext;
    }
    for (int i = 0; i < index; i++)
    {
        temp = temp->lPrev;
    }
    temp->lValue = value;
    return 0;
}
int llength(list *listptr)
{
    list *temp = listptr;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->lNext;
    }
    return length;
}
bool lcontains(list *listptr, double value)
{
    list *temp = listptr;
    while (temp != NULL)
    {
        if (temp->lValue == value)
        {
            return true;
        }
        temp = temp->lNext;
    }
    return false;
}
int lreverse(list *listptr)
{
    list *tempA = listptr, *tempB = listptr;
    int length = 0;
    double a, b, temp;
    while (tempB->lNext != NULL)
    {
        length++;
        tempB = tempB->lNext;
    }
    for (int i = 0; i < length / 2; i++)
    {
        temp = tempA->lValue;
        tempA->lValue = tempB->lValue;
        tempB->lValue = temp;
        tempA = tempA->lNext;
        tempB = tempB->lPrev;
    }
    return 0;
}

// Math functions
double root(double radicand, double index)
{
    return pow(radicand, 1 / index);
}