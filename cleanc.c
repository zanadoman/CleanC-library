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

// List definition // COMPLETE List def
struct listNode
{
    double lValue;
    struct listNode *lPrev;
    struct listNode *lNext;
};
typedef struct listNode list;


// IO functions
int scanvoid() // COMPLETE
{
    while (getchar() != '\n')
        ;
    return 0;
}

// Variable functions declarations
int swap(void *a, void *b, char size) // COMPLETE
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
int areverse(void *first, void *last, char type) // COMPLETE
{
    if (type == 3)
    {
        int temp;
        int *tempA = first;
        int *tempB = last;
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
int asort(void *first, void *last, char type) // COMPLETE
{
    if (type == 3 && first < last)
    {
        int temp;
        int *tempFirst = (int *)first - 1;
        int pivot = *(int *)last;
        for (int *i = (int *)first; i <= (int *)last; i++)
        {
            if (*i < pivot)
            {
                tempFirst++;
                temp = *tempFirst;
                *tempFirst = *i;
                *i = temp;
            }
        }
        temp = *(tempFirst + 1);
        *(tempFirst + 1) = *(int *)last;
        *(int *)last = temp;
        asort(first, tempFirst, 3);
        asort(tempFirst + 2, last, 3);
        return 0;
    }
    return 1;
}
long strint(char *string) // COMPLETE
{
    double result = 0, powskip = 1;
    char *size = string;
    for (; *size != 0; size++)
    {
        powskip *= 10;
    }
    for (; string < size; string++)
    {
        if (47 < *string && *string < 58)
        {
            powskip /= 10;
            result += (*string - 48) * powskip;
        }
        else
        {
            result /= powskip;
            break;
        }
    }
    return result;
}
double strdouble(char *string) // COMPLETE
{
    double result = 0, powskip = 1;
    int floatingpoint = 1;
    char *size = string;
    for (; *size != 0; size++)
    {
        powskip *= 10;
    }
    for (; string < size; string++)
    {
        if (47 < *string && *string < 58)
        {
            powskip /= 10;
            result += (*string - 48) * powskip;
        }
        else if (*string == 46)
        {
            floatingpoint = powskip;
        }
        else
        {
            result = 0;
            break;
        }
    }
    return result / floatingpoint;
}

// List functions
int ladd(list **listptr, double value) // COMPLETE
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
int linsert(list *listptr, int index, double value) // COMPLETE
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
int lremove(list **listptr, int index) // COMPLETE
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
double lvalue(list *listptr, int index) // COMPLETE
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
int lchange(list *listptr, int index, int value) // COMPLETE
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
int llength(list *listptr) // COMPLETE
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
bool lcontains(list *listptr, double value) // COMPLETE
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
int lreverse(list *listptr) // COMPLETE
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
double root(double radicand, double index) // COMPLETE
{
    return pow(radicand, 1 / index);
}