#ifndef QUEUE_H
#define QUEUE_H
#include "item.h"

typedef struct queue* Q;
int QUEUEcount(Q);
Q QUEUEinit(int);
int QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);
void QUEUEdestroy(Q);

#endif
