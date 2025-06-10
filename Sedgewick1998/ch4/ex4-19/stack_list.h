#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <stdio.h>

typedef struct node {
    float item;
    struct node* next;
} node;

void STACKinit(void);
void STACKpush(float);
float STACKpop(void);
int STACKempty(void);
size_t STACKcount(void);

#endif
