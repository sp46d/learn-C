// Exercise 3.37. Implement a code fragment for a linked list that exchanges the
// positions of the nodes after the nodes referenced by two given links t and u.

// input list:  1 2 3 4 5 6 7 8
// link t: 3
// link u: 6
// output list: 1 2 3 (7) 5 6 (4) 8

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    link l = malloc(sizeof(*l));
    link x = l;

    srand(time(NULL));
    l->item = rand() % M;
    l->next = NULL;
    for (int i = 1; i < N; i++) {
        x->next = malloc(sizeof(*x));
        x = x->next;
        x->item = rand() % M;
        x->next = NULL;
    }

    printf("before:\n");
    for (link a = l; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");

    // code fragment for this exercise begins here
    link t = l;
    link u = l;
    // suppose that t is 3rd node in the list
    for (int i = 1; i < 3; i++)
        t = t->next;
    // suppose that u is 6th node in the list
    for (int i = 1; i < 6; i++)
        u = u->next;
    // Swap the nodes after links t and u
    link next_t = t->next;
    link next_next_u = u->next->next;
    u->next->next = next_t->next;
    t->next = u->next;
    next_t->next = next_next_u;
    u->next = next_t;

    printf("after:\n");
    for (link a = l; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");
}