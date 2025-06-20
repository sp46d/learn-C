#ifndef QUEUE_H
#define QUEUE_H

#include "item.h"

void QUEUEinit(void);
int QUEUEempty(void);
void QUEUEput(Item);
Item QUEUEget(void);
void QUEUEdump(void);

#endif
