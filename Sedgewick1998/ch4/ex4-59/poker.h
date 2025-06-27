#ifndef POKER_H
#define POKER_H

#include "agent.h"
#include "card.h"
#include "cstack.h"
#include "deck.h"

void POKERinit(int); // set the number of players
void POKERbegin(void);
char POKERprompt(void);
void POKERdestroy(void);

#endif
