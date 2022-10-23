#include <stdio.h>
#include "cleanc.h"

int main()
{
    double x = 10;
    double y = 20;

    swap(&x, &y, DOUBLE);
    printf("%lf, %lf\n", x, y);

    return 0;
}