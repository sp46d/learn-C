// Array implementation

#include "cstack.h"
#include "card.h"
#include <stdio.h>
#include <stdlib.h>

struct cstack {
    int n; // index of current top
    Card stack[52];
};

Cstack CSTACKinit(void)
{
    Cstack new = malloc(sizeof(struct cstack));
    for (int i = 0; i < 52; i++) {
        new->stack[i] = NULL;
    }
    new->n = 0;
    return new;
}

int CSTACKempty(Cstack s) { return s->n == 0; }

void CSTACKpush(Cstack s, Card c)
{
    if (s->n == 52) {
        printf("Error: Stack is full\n");
        return;
    }
    s->stack[s->n] = c;
    s->n++;
}

Card CSTACKpop(Cstack s)
{
    if (CSTACKempty(s)) {
        printf("Error: Stack is empty\n");
        return NULL;
    }
    s->n--;
    return s->stack[s->n];
}

Card CSTACKget(Cstack s, int k)
{
    if (k >= s->n) {
        printf("Error: Index out of bounds\n");
        return NULL;
    }
    return s->stack[k];
}

void CSTACKdestroy(Cstack s)
{
    for (int i = 0; i < 52; i++) {
        if (s->stack[i] != NULL) {
            free(s->stack[i]);
        }
    }
    free(s);
}

int CSTACKcount(Cstack s) { return s->n; }
