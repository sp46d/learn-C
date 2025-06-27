// First-class ADT for queue using an array implementation

#include "queue.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct queue {
    Item* queue;
    int N;
    int head;
    int tail;
    int n_items;
};

Q QUEUEinit(int maxN)
{
    Q new = malloc(sizeof(*new));
    new->queue = malloc(maxN * sizeof(Item));
    new->N = maxN;
    new->head = maxN;
    new->tail = 0;
    new->n_items = 0;
    return new;
}

int QUEUEempty(Q x) { return x->head % x->N == x->tail; }

void QUEUEput(Q x, Item item)
{
    x->queue[x->tail] = item;
    x->tail++;
    x->tail = x->tail % x->N;
    x->n_items++;
}

Item QUEUEget(Q x)
{
    if (QUEUEempty(x)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    x->head = x->head % x->N;
    x->n_items--;
    return x->queue[x->head++];
}

void QUEUEdestroy(Q x)
{
    free(x->queue);
    free(x);
}

int QUEUEcount(Q x) { return x->n_items; }
