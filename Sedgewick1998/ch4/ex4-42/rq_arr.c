// Exercise 4.42
// Build a random-queue ADT by writing an interface and an implementation that
// uses an array as the underlying data structure. Make sure that each operation
// takes constant time.

// My initial thoughts:
// It's a little tricky as to how to handle index when popping an element. It
// somehow needs to track which index has got generated thus far, because
// generating duplicate indices won't work. The key is, when running the pop
// operation we get the targeted value AND remove the chosen value from the
// array at the same time. And it all has to work in a constant time (i.e. not
// depending on the size of the array). Shifting elements of the array every
// time the pop operation is run won't work, because its running time depends on
// the size of array, not a constant time.
//
// I might have to maintain another array solely for tracking which index has
// been drawn.
// NO NEED TO MAINTAIN ANOTHER ARRAY!
// When an element got chosen, we move the last element to the chose position,
// overwriting the element in that position.

#include "rq.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int* rq;
static int N;
static int tail;
static int n_elements;

void RQinit(int maxN)
{
    N = maxN;
    rq = malloc(N * sizeof(*rq));
    tail = 0;
    n_elements = 0;
}

int RQempty(void) { return n_elements == 0; }

void RQpush(int x)
{
    if (n_elements >= N) {
        printf("Error: Queue is full. Can't perform push operation\n");
        return;
    }
    rq[tail++] = x;
    n_elements++;
}

int RQpop(void)
{
    if (RQempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    srand(time(NULL));
    int r = rand() % tail; // generate a random index
    int retval = rq[r];
    tail--;
    rq[r] = rq[tail];
    n_elements--;
    return retval;
}
