#include "two_stacks.h"
#include <stdio.h>
#include <stdlib.h>

static int* stack;
static int N = 0;
static int M = 0;
static int maxN;

void STACKSinit(int n1, int n2)
{
    maxN = n1 + n2;
    stack = malloc(maxN * sizeof(*stack));
}

void STACKpush(int n, int d)
{
    if (n < 0 || n > 1) {
        printf("Error: Wrong number used when referring to stacks. Use either "
               "0 or 1 to refer to which stack you want to push a value to\n");
        return;
    }

    if (n == 0) {
        // if n equals 0, it refers to the first stack, which starts at the
        // beginning of the array.
        stack[N++] = d;
    } else {
        // if n equals 1, it refers to the second stack, which starts at the
        // end of the array
        stack[maxN - 1 - M] = d;
        M++;
    }
}

int STACKpop(int n)
{
    if (n < 0 || n > 1) {
        printf("Error: Wrong number used when referring to stacks. Use either "
               "0 or 1 to refer to which stack you want to pop a value from\n");
        return -1;
    }

    if (STACKempty(n)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return (n == 0) ? stack[--N] : stack[maxN - 1 - (--M)];
}

int STACKempty(int n)
{
    if (n < 0 || n > 1) {
        printf("Error: Wrong number used when referring to stacks. Use either "
               "0 or 1 to refer to which stack you want check if it's empty\n");
        return -1;
    }
    return (n == 0) ? N == 0 : M == 0;
}