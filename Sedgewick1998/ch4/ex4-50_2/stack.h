#ifndef STACK_H
#define STACK_H

#include "item.h"

void STACKinit(void);
int STACKempty(void);
void STACKpush(Item);
Item STACKpop(void);
char* STACKdump(void);

#endif
