/* CleanC.h - 2022Q4 - Version beta
Developed by: Doman Zana, for the sake of humanity
and to make C a clean and modern programming language. */

//Includes
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
    int size;
    bool ordered;
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
/*int areverse(void *array, long arraySize, char arrayType)
{
    long temp;
    switch (arrayType)
    {
    case 1:
        char *arrayStart1 = (char *)array;
        char *arrayEnd1 = arrayStart1 + --arraySize;
        for (; arrayStart1 < arrayEnd1; arrayStart1++, arrayEnd1--)
        {
            temp = *arrayStart1;
            *arrayStart1 = *arrayEnd1;
            *arrayEnd1 = temp;
        }
        break;
    case 2:
        short *arrayStart2 = (short *)array;
        short *arrayEnd2 = arrayStart2 + --arraySize;
        for (; arrayStart2 < arrayEnd2; arrayStart2++, arrayEnd2--)
        {
            temp = *arrayStart2;
            *arrayStart2 = *arrayEnd2;
            *arrayEnd2 = temp;
        }
        break;
    case 3:
        int *arrayStart3 = (int *)array;
        int *arrayEnd3 = arrayStart3 + --arraySize;
        for (; arrayStart3 < arrayEnd3; arrayStart3++, arrayEnd3--)
        {
            temp = *arrayStart3;
            *arrayStart3 = *arrayEnd3;
            *arrayEnd3 = temp;
        }
        break;
    case 4:
        long *arrayStart4 = (long *)array;
        long *arrayEnd4 = arrayStart4 + --arraySize;
        for (; arrayStart4 < arrayEnd4; arrayStart4++, arrayEnd4--)
        {
            temp = *arrayStart4;
            *arrayStart4 = *arrayEnd4;
            *arrayEnd4 = temp;
        }
        break;
    case 5:
        float *arrayStart5 = (float *)array;
        float *arrayEnd5 = arrayStart5 + --arraySize;
        for (; arrayStart5 < arrayEnd5; arrayStart5++, arrayEnd5--)
        {
            temp = *arrayStart5;
            *arrayStart5 = *arrayEnd5;
            *arrayEnd5 = temp;
        }
        break;
    case 6:
        double *arrayStart6 = (double *)array;
        double *arrayEnd6 = arrayStart6 + --arraySize;
        for (; arrayStart6 < arrayEnd6; arrayStart6++, arrayEnd6--)
        {
            temp = *arrayStart6;
            *arrayStart6 = *arrayEnd6;
            *arrayEnd6 = temp;
        }
        break;
    }
    return 0;
}*/

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
    long temp;
    switch (size)
    {
    case 1:
        temp = *(char *)a;
        *(char *)a = *(char *)b;
        *(char *)b = temp;
        break;
    case 2:
        temp = *(short *)a;
        *(short *)a = *(short *)b;
        *(short *)b = temp;
        break;
    case 4:
        temp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = temp;
        break;
    case 8:
        temp = *(long *)a;
        *(long *)a = *(long *)b;
        *(long *)b = temp;
        break;
    }
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

    if (*listptr == nodeToRemove)
    {
        *listptr = nodeToRemove->lNext;
        if (*listptr != NULL)
        {
            (*listptr)->lPrev = NULL;
        }
    }
    else
    {
        nodeToRemove->lPrev->lNext = nodeToRemove->lNext;
        if (nodeToRemove->lNext != NULL)
        {
            nodeToRemove->lNext->lPrev = nodeToRemove->lPrev;
        }
    }
    nodeToRemove->lNext = NULL;
    nodeToRemove->lPrev = NULL;
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