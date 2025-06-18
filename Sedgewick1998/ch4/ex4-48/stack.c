#include "stack.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

static Item* s;
static int N;

void STACKinit(maxN)
{
    s = malloc(maxN * sizeof(*s));
    N = 0;
}

int STACKempty(void) { return N == 0; }

void STACKpush(Item x)
{
    for (int i = 0; i < N; i++) {
        if (eq(s[i], x)) {
            printf("Error: Received item already in the list\n");
            return;
        }
    }
    s[N++] = x;
}

Item STACKpop(void) { return s[--N]; }
