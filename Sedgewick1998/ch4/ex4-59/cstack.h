#ifndef CSTACK_H
#define CSTACK_H
#include "card.h"

typedef struct cstack* Cstack;
Cstack CSTACKinit(void);
void CSTACKpush(Cstack, Card);
// Get a card on top of the stack and remove it from the stack at a constant
// time
Card CSTACKpop(Cstack);
// Get a card at a specific index (starts from 0), which however doesn't remove
// the card from the stack
Card CSTACKget(Cstack, int);
int CSTACKempty(Cstack);
void CSTACKdestroy(Cstack);
int CSTACKcount(Cstack);

#endif
