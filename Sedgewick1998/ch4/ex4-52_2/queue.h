#ifndef QUEUE_H
#define QUEUE_H

#include "item.h"

void QUEUEinit(int);
int QUEUEempty(void);
void QUEUEput(Item);
Item QUEUEget(void);
void QUEUEdump(void);

#endif
