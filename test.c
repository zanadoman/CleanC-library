#include <stdio.h>
#include "cleanc.h"

int main()
{
    long x = 423;
    long y = 8678;

    swap(&x, &y, LONG);
    printf("%ld, %ld\n", x, y);

    return 0;
}