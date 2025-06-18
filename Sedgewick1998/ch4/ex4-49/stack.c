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
            N--;
            for (int j = i; j < N; j++) {
                s[j] = s[j + 1];
            }
        }
    }
    s[N++] = x;
}

Item STACKpop(void)
{
    if (STACKempty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return s[--N];
}

void STACKdump(void)
{
    for (int i = 0; i < N; i++) {
        printf("%c ", s[i]);
    }
    printf("\n");
}
