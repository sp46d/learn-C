// Too complicated. I don't think it's a good idea to maintain mid node. Give it
// another approach, but for now, let's move on.

#include "rq.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int item;
    struct node* next;
} node;

static node* head;
static int n_elements;

static node* NEW(int x, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->next = next;
    return new;
}

void RQinit(void)
{
    head = NULL;
    n_elements = 0;
}

int RQempty(void) { return n_elements == 0; }

void RQpush(int x)
{
    node* new = NEW(x, head);
    n_elements++;
    head = new;
}

int RQpop(void)
{
    if (RQempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval;
    node* t;
    srand(time(NULL));
    int r = rand() % n_elements;
    if (r == 0) {
        retval = head->item;
        t = head->next;
        free(head);
        head = t;
    } else {
        t = head;
        for (int i = 0; i < r - 1; i++) {
            t = t->next;
        }
        node* s = t->next;
        retval = s->item;
        t->next = s->next;
        free(s);
    }
    n_elements--;
    return retval;
}
