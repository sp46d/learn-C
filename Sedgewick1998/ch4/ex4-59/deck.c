#include "deck.h"
#include "cstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct deck {
    int n_cards;
    Card cards[52];
};

Deck DECKinit(void)
{
    Deck new = malloc(sizeof(struct deck));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            new->cards[i * 13 + j] = CARDinit(i, j);
        }
    }
    new->n_cards = 52;
    return new;
}

Card DECKdraw(Deck a)
{
    srand(time(NULL));
    int r = rand() % a->n_cards;
    Card drawn_card = a->cards[r];
    a->n_cards--;
    a->cards[r] = a->cards[a->n_cards];
    return drawn_card;
}

int DECKcount(Deck a) { return a->n_cards; }

void DECKdestroy(Deck a)
{
    for (int i = 0; i < DECKcount(a); i++) {
        free(a->cards[i]);
    }
    free(a);
}
