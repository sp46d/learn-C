#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static int* queue;
static int N;
static int head;
static int tail;
static int is_full = 0;

void QUEUEinit(int maxN)
{
    N = maxN + 1;
    queue = malloc(N * sizeof(*queue));
    head = N;
    tail = 0;
}

int QUEUEempty(void) { return (head % N == tail) && !is_full; }

void QUEUEput(int x)
{
    if (is_full) {
        QUEUEerror();
        return;
    }
    queue[tail++] = x;
    tail = tail % N;
    if (head % N == tail) {
        is_full = 1;
    }
}

int QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("\n");
        QUEUEerror();
        return -1;
    }
    is_full = 0;
    head = head % N;
    return queue[head++];
}

void QUEUEerror(void)
{
    if (is_full) {
        printf("Error: Queue is full. Can't put more values on to the queue\n");
    } else {
        printf("Error: Queue is empty. Can't get a value from the queue\n");
    }
}
