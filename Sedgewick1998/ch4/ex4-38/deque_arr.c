#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

static int* deque;
static int N;
static int head;
static int tail;
static int n_elements = 0;

void DEQUEinit(int maxN)
{
    N = maxN + 1;
    deque = malloc(N * sizeof(*deque));
    head = N;
    tail = 0;
}

void DEQUEpush_l(int x)
{
    if (!DEQUEempty()) {
        head--;
    }
    head = (N + head) % N;
    deque[head] = x;
    n_elements++;
}

int DEQUEpop_l(void)
{
    if (DEQUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    head = head % N;
    int tmp = deque[head];
    head++;
    n_elements--;
    return tmp;
}

void DEQUEpush_r(int x)
{
    if (!DEQUEempty()) {
        tail++;
    }
    tail = tail % N;
    deque[tail] = x;
    n_elements++;
}

int DEQUEpop_r(void)
{
    if (DEQUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    tail = (N + tail) % N;
    int tmp = deque[tail];
    tail--;
    n_elements--;
    return tmp;
}

int DEQUEempty(void) { return n_elements == 0; }
