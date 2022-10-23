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
    struct listNode *lPrev;
    struct listNode *lNext;
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
    nodeNew->lPrev = *listptr;
    nodeNew->lNext = NULL;
    if (*listptr != NULL)
    {
        (*listptr)->lNext = nodeNew;
    }
    *listptr = nodeNew;
    return 0;
}
int linsert(list *listptr, int index, double value)
{
    list *nodeInsertAfter = listptr;
    while (nodeInsertAfter->lPrev != NULL)
    {
        nodeInsertAfter = nodeInsertAfter->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        nodeInsertAfter = nodeInsertAfter->lNext;
    }
    list *nodeNew = malloc(sizeof(struct listNode));
    nodeNew->lValue = value;
    if (nodeInsertAfter->lPrev == NULL)
    {
        nodeNew->lNext = nodeInsertAfter;
        nodeNew->lPrev = NULL;
        nodeInsertAfter->lPrev = nodeNew;
    }
    else
    {
        nodeNew->lNext = nodeInsertAfter;
        nodeNew->lPrev = nodeInsertAfter->lPrev;
        nodeInsertAfter->lPrev = nodeNew;
        nodeNew->lPrev->lNext = nodeNew;
    }
}
int lremove(list **listptr, int index)
{
    list *nodeToRemove = *listptr;
    while (nodeToRemove->lPrev != NULL)
    {
        nodeToRemove = nodeToRemove->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        nodeToRemove = nodeToRemove->lNext;
    }
    if (nodeToRemove->lNext != NULL)
    {
        nodeToRemove->lNext->lPrev = nodeToRemove->lPrev;
    }
    if (nodeToRemove->lPrev != NULL)
    {
        nodeToRemove->lPrev->lNext = nodeToRemove->lNext;
    }
    if (nodeToRemove == *listptr)
    {
        *listptr = nodeToRemove->lPrev;
    }
    nodeToRemove->lNext = nodeToRemove->lPrev = NULL;
    return 0;
}
double lvalue(list *listptr, int index)
{
    list *temp = listptr;
    while (temp->lPrev != NULL)
    {
        temp = temp->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        temp = temp->lNext;
    }
    return temp->lValue;
}
int lchange(list *listptr, int index, int value)
{
    list *temp = listptr;
    while (temp->lPrev != NULL)
    {
        temp = temp->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        temp = temp->lNext;
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
        temp = temp->lPrev;
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
        temp = temp->lPrev;
    }
    return false;
}
int lreverse(list *listptr)
{
    list *tempA = listptr, *tempB = listptr;
    int length = 0;
    double a, b, temp;
    while (tempB->lPrev != NULL)
    {
        length++;
        tempB = tempB->lPrev;
    }
    for (int i = 0; i < length / 2; i++)
    {
        temp = tempA->lValue;
        tempA->lValue = tempB->lValue;
        tempB->lValue = temp;
        tempA = tempA->lPrev;
        tempB = tempB->lNext;
    }
    return 0;
}

// Math functions
double root(double radicand, double index)
{
    return pow(radicand, 1 / index);
}