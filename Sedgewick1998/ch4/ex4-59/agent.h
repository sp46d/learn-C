#ifndef AGENT_H
#define AGENT_H

#include "card.h"

typedef struct agent* Agent;
Agent AGENTinit(void);
void AGENTgetcard(Agent, Card);
Card AGENTpickcard(Agent, int);
void AGENTshowcards(Agent, int isfaceup);
int AGENTcount(Agent);
void AGENTdestroy(Agent);

#endif
