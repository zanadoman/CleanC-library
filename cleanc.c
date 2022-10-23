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

// IO functions
int scanvoid()
{
    while (getchar() != '\n')
        ;
    return 0;
}

// Variable functions declarations
int swap(void *a, void *b, char size)
{
    if (size == 1)
    {
        char temp = *(char *)a;
        *(char *)a = *(char *)b;
        *(char *)b = temp;
        return 0;
    }
    else if (size == 2)
    {
        short temp = *(short *)a;
        *(short *)a = *(short *)b;
        *(short *)b = temp;
        return 0;
    }
    else if (size == 3)
    {
        int temp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = temp;
        return 0;
    }
    else if (size == 4)
    {
        long temp = *(long *)a;
        *(long *)a = *(long *)b;
        *(long *)b = temp;
        return 0;
    }
    else if (size == 5)
    {
        float temp = *(float *)a;
        *(float *)a = *(float *)b;
        *(float *)b = temp;
        return 0;
    }
    else if (size == 6)
    {
        double temp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = temp;
        return 0;
    }
    return 1;
}

// Array functions declarations
int areverse(array *a)
{
    if (a->type == 1)
    {
        char *tempA = (char *)a->ptr;
        char *tempB = (char *)a->ptr + a->length - 1;
        short temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (a->type == 2)
    {
        short *tempA = (short *)a->ptr;
        short *tempB = (short *)a->ptr + a->length - 1;
        short temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (a->type == 3)
    {
        int *tempA = (int *)a->ptr;
        int *tempB = (int *)a->ptr + a->length - 1;
        int temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (a->type == 4)
    {
        long *tempA = (long *)a->ptr;
        long *tempB = (long *)a->ptr + a->length - 1;
        long temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (a->type == 5)
    {
        float *tempA = (float *)a->ptr;
        float *tempB = (float *)a->ptr + a->length - 1;
        float temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (a->type == 6)
    {
        double *tempA = (double *)a->ptr;
        double *tempB = (double *)a->ptr + a->length - 1;
        double temp;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    return 1;
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