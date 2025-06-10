#include "stack_list.h"
#include <stdio.h>
#include <stdlib.h>

static node* stack;

void STACKinit(void) { stack = NULL; }

void STACKpush(float f)
{
    node* new = malloc(sizeof(*new));
    new->next = stack;
    new->item = f;
    stack = new;
}

float STACKpop(void)
{
    float retval = stack->item;
    node* tmp = stack;
    stack = stack->next;
    free(tmp);
    return retval;
}

int STACKempty(void) { return STACKcount() == 0; }

size_t STACKcount(void)
{
    size_t cnt = 0;
    for (node* sp = stack; sp != NULL; sp = sp->next) {
        cnt++;
    }
    return cnt;
}