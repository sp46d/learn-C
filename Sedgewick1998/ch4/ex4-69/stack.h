#ifndef STACK_H
#define STACK_H

#include "complex.h"
typedef struct stack* Stack;
Stack STACKinit(void);
void STACKpush(Stack, Complex);
Complex STACKpop(Stack);
int STACKempty(Stack);
void STACKdestroy(Stack);

#endif
