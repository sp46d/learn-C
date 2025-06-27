#ifndef DECK_H
#define DECK_H

#include "card.h"
typedef struct deck* Deck;

Deck DECKinit(void);
Card DECKdraw(Deck);
int DECKcount(Deck);
void DECKdestroy(Deck);

#endif
