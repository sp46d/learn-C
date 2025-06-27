#include "agent.h"
#include "card.h"
#include "cstack.h"
#include <stdio.h>
#include <stdlib.h>

struct agent {
    Cstack cards;
};

Agent AGENTinit(void)
{
    Agent new = malloc(sizeof(struct agent));
    new->cards = CSTACKinit();
    return new;
}

void AGENTgetcard(Agent a, Card c) { CSTACKpush(a->cards, c); }

Card AGENTpickcard(Agent a, int n)
{
    int cnt = AGENTcount(a);
    if (n >= cnt) {
        printf("Error: Chosen card does not exist. Choose from 0 to %d\n",
            cnt - 1);
        return NULL;
    }
    return CSTACKget(a->cards, n);
}

void AGENTshowcards(Agent a, int isfaceup)
{
    for (int i = 0; i < AGENTcount(a); i++) {
        if (isfaceup) {
            CARDshow(AGENTpickcard(a, i));
        } else {
            printf("[?]");
        }
        printf(" ");
    }
    printf("\n");
}

void AGENTdestroy(Agent a)
{
    CSTACKdestroy(a->cards);
    free(a);
}

int AGENTcount(Agent a) { return CSTACKcount(a->cards); }
