// Implement no-duplicates with a forget-the-old-item policy.

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
    head = head % N;
    for (int i = head; i != tail; i = (i + 1) % N) {
        if (eq(queue[i], item)) {
            for (int j = i; j != tail; j = (j + 1) % N) {
                queue[j] = queue[j + 1];
            }
            tail = (tail + N - 1) % N;
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
