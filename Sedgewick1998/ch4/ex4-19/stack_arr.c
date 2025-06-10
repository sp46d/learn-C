#include "stack_arr.h"
#include <stdio.h>
#include <stdlib.h>

static float* stack;
static size_t N = 0;

void STACKinit(int n) { stack = malloc(n * sizeof(*stack)); }

void STACKpush(float f) { stack[N++] = f; }

float STACKpop(void)
{
    if (STACKempty()) {
        return 0.0;
    }
    return stack[--N];
}

int STACKempty(void) { return STACKcount() == 0; }

size_t STACKcount(void) { return N; }
