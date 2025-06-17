#ifndef DEQUE_H
#define DEQUE_H

void DEQUEinit(void);
void DEQUEpush_l(int); // Insert a value at the beginning (i.e. head)
int DEQUEpop_l(void); // Get the value at the beginning (i.e. head)
void DEQUEpush_r(int); // Insert a value at the end (i.e. tail)
int DEQUEpop_r(void); // Get the value at the end (i.e. tail)
int DEQUEempty(void);
void DEQUEdump(void);

#endif
