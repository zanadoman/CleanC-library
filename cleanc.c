/* CleanC.h - 2022Q4 - Version beta
Developed by: Doman Zana, for the sake of humanity
and to make C a clean and modern programming language. */


// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Bool definition
#define true 1
#define false 0
typedef char bool;

// List definition // COMPLETE
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
int swap(void *a, void *b, char type) // COMPLETE
{
    if (type == 1)
    {
        char temp = *(char *)a;
        *(char *)a = *(char *)b;
        *(char *)b = temp;
        return 0;
    }
    else if (type == 2)
    {
        short temp = *(short *)a;
        *(short *)a = *(short *)b;
        *(short *)b = temp;
        return 0;
    }
    else if (type == 3)
    {
        int temp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = temp;
        return 0;
    }
    else if (type == 4)
    {
        long temp = *(long *)a;
        *(long *)a = *(long *)b;
        *(long *)b = temp;
        return 0;
    }
    else if (type == 5)
    {
        float temp = *(float *)a;
        *(float *)a = *(float *)b;
        *(float *)b = temp;
        return 0;
    }
    else if (type == 6)
    {
        double temp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = temp;
        return 0;
    }
    return 1;
}

// Array functions declarations
bool acontint(void *first, void *last, int value, char type) // COMPLETE
{
    if (type == 1)
    {
        for (; first <= last; first++)
        {
            if (*(char *)first == value)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for (; first <= last; first++)
        {
            if (*(short *)first == value)
            {
                return true;
            }
        }
    }
    else if (type == 3)
    {
        for (; first <= last; first++)
        {
            if (*(int *)first == value)
            {
                return true;
            }
        }
    }
    else if (type == 4)
    {
        for (; first <= last; first++)
        {
            if (*(long *)first == value)
            {
                return true;
            }
        }
    }
    return false;
}
bool acontdouble(void *first, void *last, int value, char type) // COMPLETE
{
    if (type == 5)
    {
        for (; first <= last; first++)
        {
            if (*(float *)first == value)
            {
                return true;
            }
        }
    }
    if (type == 6)
    {
        for (; first <= last; first++)
        {
            if (*(double *)first == value)
            {
                return true;
            }
        }
    }
    return false;
}
int areverse(void *first, void *last, char type) // COMPLETE
{
    if (type == 1)
    {
        char temp;
        char *tempA = first;
        char *tempB = last;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (type == 2)
    {
        short temp;
        short *tempA = first;
        short *tempB = last;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (type == 3)
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
    else if (type == 4)
    {
        long temp;
        long *tempA = first;
        long *tempB = last;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (type == 5)
    {
        float temp;
        float *tempA = first;
        float *tempB = last;
        for (; tempA < tempB; tempA++, tempB--)
        {
            temp = *tempA;
            *tempA = *tempB;
            *tempB = temp;
        }
        return 0;
    }
    else if (type == 6)
    {
        double temp;
        double *tempA = first;
        double *tempB = last;
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
    if (type == 1 && first < last)
    {
        char temp;
        char *tempFirst = (char *)first - 1;
        char pivot = *(char *)last;
        for (char *i = (char *)first; i <= (char *)last; i++)
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
        *(tempFirst + 1) = *(char *)last;
        *(char *)last = temp;
        asort(first, tempFirst, 3);
        asort(tempFirst + 2, last, 3);
        return 0;
    }
    else if (type == 2 && first < last)
    {
        short temp;
        short *tempFirst = (short *)first - 1;
        short pivot = *(short *)last;
        for (short *i = (short *)first; i <= (short *)last; i++)
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
        *(tempFirst + 1) = *(short *)last;
        *(short *)last = temp;
        asort(first, tempFirst, 3);
        asort(tempFirst + 2, last, 3);
        return 0;
    }
    else if (type == 3 && first < last)
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
    else if (type == 4 && first < last)
    {
        long temp;
        long *tempFirst = (long *)first - 1;
        long pivot = *(long *)last;
        for (long *i = (long *)first; i <= (long *)last; i++)
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
        *(tempFirst + 1) = *(long *)last;
        *(long *)last = temp;
        asort(first, tempFirst, 3);
        asort(tempFirst + 2, last, 3);
        return 0;
    }
    else if (type == 5 && first < last)
    {
        float temp;
        float *tempFirst = (float *)first - 1;
        float pivot = *(float *)last;
        for (float *i = (float *)first; i <= (float *)last; i++)
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
        *(tempFirst + 1) = *(float *)last;
        *(float *)last = temp;
        asort(first, tempFirst, 3);
        asort(tempFirst + 2, last, 3);
        return 0;
    }
    else if (type == 6 && first < last)
    {
        double temp;
        double *tempFirst = (double *)first - 1;
        double pivot = *(double *)last;
        for (double *i = (double *)first; i <= (double *)last; i++)
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
        *(tempFirst + 1) = *(double *)last;
        *(double *)last = temp;
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
    while (listptr->lPrev != NULL)
    {
        listptr = listptr->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        listptr = listptr->lNext;
    }
    list *nodeNew = malloc(sizeof(struct listNode));
    nodeNew->lValue = value;
    if (listptr->lPrev == NULL)
    {
        nodeNew->lNext = listptr;
        nodeNew->lPrev = NULL;
        listptr->lPrev = nodeNew;
    }
    else
    {
        nodeNew->lNext = listptr;
        nodeNew->lPrev = listptr->lPrev;
        listptr->lPrev = nodeNew;
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
    while (listptr->lPrev != NULL)
    {
        listptr = listptr->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        listptr = listptr->lNext;
    }
    return listptr->lValue;
}
int lchange(list *listptr, int index, int value) // COMPLETE
{
    while (listptr->lPrev != NULL)
    {
        listptr = listptr->lPrev;
    }
    for (int i = 0; i < index; i++)
    {
        listptr = listptr->lNext;
    }
    listptr->lValue = value;
    return 0;
}
int llength(list *listptr) // COMPLETE
{
    int length = 0;
    while (listptr != NULL)
    {
        length++;
        listptr = listptr->lPrev;
    }
    return length;
}
bool lcontains(list *listptr, int first, int last, double value) // COMPLETE
{
    while (listptr->lPrev != NULL)
    {
        listptr = listptr->lPrev;
    }
    for (int i = 0; i < first; i++)
    {
        listptr = listptr->lNext;
    }
    for (int i = 0; i < last - first + 1; i++)
    {
        if (listptr->lValue == value)
        {
            return true;
        }
        listptr = listptr->lNext;
    }
    return false;
}
int lreverse(list *listptr, int first, int last) // COMPLETE
{
    list *tempA, *tempB;
    double temp;
    while (listptr->lPrev != NULL)
    {
        listptr = listptr->lPrev;
    }
    tempA = tempB = listptr;
    for (int i = 0; i < first; i++)
    {
        tempA = tempA->lNext;
    }
    for (int i = 0; i < last; i++)
    {
        tempB = tempB->lNext;
    }
    for (int i = 0; i < (last - first + 1) >> 1; i++)
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
int randinit() // COMPLETE
{
    srand(time(0));
    return 0;
}
long random(long min, long max) // COMPLETE
{
    return (rand() % (max - min + 1)) + min;
}
double root(double radicand, double index) // COMPLETE
{
    return pow(radicand, 1 / index);
}