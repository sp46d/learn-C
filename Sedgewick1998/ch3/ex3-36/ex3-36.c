// Write a function that rearranges a linked list to put the nodes in even
// positions after the nodes in odd positions in the list, preserving the
// relative order of both the evens and the odds.

// The exercise sounds a little ambiguous to me, but the way I understand this
// exercise is as follows:
// Given the input list of { 1 2 3 4 5 6 7 8 9 10 } it should return the output
// list of { 1 3 5 7 9 2 4 6 8 10 }

// And it says we do rearrange a linked list, so all the arrangements are
// supposed to occur in place.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

link even_after_odd(link list)
{
    // TODO: Do this again without using dummy head or dummy tail

    // if the given list has only one node or two nodes in it, return the same
    // list as is.
    if (list->next == NULL || list->next->next == NULL)
        return list;

    // To tackle this exercise, I maintain two separate lists, odds and evens,
    // throughout the function. I then add all the odd nodes to odds and all the
    // even nodes to evens, during which I keep the relative positions of nodes
    // in both odds and evens. These two lists, odds and evens, get merged right
    // before the end of the function, that is, the last node of the odds gets
    // connected to the first node of the evens.

    // To accomplish this task, I employ dummy head and dummy tail for each of
    // odds and evens. I use dummy head to insert the first node into the list
    // and dummy tail to prevent the function from invoking next field from NULL
    // pointer.
    link odds_head = malloc(sizeof(*odds_head)); // dummy head for odds
    link evens_head = malloc(sizeof(*evens_head)); // dummy head for evens
    link tail = malloc(sizeof(*tail)); // dummy tail
    tail->next
        = tail; // dummy tail points to itself, so it never points to NULL
    link a;
    for (a = list; a->next != NULL; a = a->next)
        ;
    // replace the NULL tail of the original list with dummy tail that points to
    // itself
    a->next = tail;

    link odds = odds_head;
    link evens = evens_head;
    link x;
    // Main loop begins.
    for (x = list; x != tail; x = x->next->next) {
        odds->next = x;
        odds = odds->next;
        evens->next = x->next;
        // When the length of the original list is odd, dummy tail will get
        // included in evens if we don't have the guard statement like below.
        if (evens->next != tail)
            evens = evens->next;
    }

    odds->next = evens_head->next;

    evens->next = NULL;
    return odds_head->next;
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    link t = malloc(sizeof(*t));
    link x = t;

    srand(time(NULL));
    t->item = rand() % M;
    t->next = NULL;
    for (int i = 1; i < N; i++) {
        x->next = malloc(sizeof(*x));
        x = x->next;
        x->item = rand() % M;
        x->next = NULL;
    }

    printf("before:\n");
    for (link a = t; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");

    link after = even_after_odd(t);
    printf("after:\n");
    for (link a = after; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");
}