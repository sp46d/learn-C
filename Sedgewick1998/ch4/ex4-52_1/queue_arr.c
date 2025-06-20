#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static Item* queue;
static int N;
static int head;
static int tail;

void QUEUEinit(int maxN)
{
    queue = malloc(maxN * sizeof(*queue));
    N = maxN;
    head = N;
    tail = 0;
}

int QUEUEempty(void) { return head % N == tail; }

void QUEUEput(Item item)
{
    int i;
    head = head % N;
    for (i = head; i != tail; i = (i + 1) % N) {
        if (eq(queue[i], item)) {
            return;
        }
    }
    queue[tail++] = item;
    tail = tail % N;
}

Item QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    head = head % N;
    return queue[head++];
}

void QUEUEdump(void)
{
    int i;
    head = head % N;
    for (i = head; i != tail; i = (i + 1) % N) {
        printf("%c ", queue[i]);
    }
}
