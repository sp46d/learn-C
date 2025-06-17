// With the circular list, I realize I don't have to maintain both head and tail
// nodes. Maintaining only the head node will do the job. As with other
// algorithms, however, saving space by maintaining only one pointer, not both,
// comes at a cost of running time. Now we have to loop through the list every
// time we run either put or get operation. This might not be a good choice for
// some problems.

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* next;
} node;

static node* head;

static node* NEW(int x, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->next = next;
    return new;
}

void QUEUEinit(void) { head = NULL; }

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(int x)
{
    node* new = NEW(x, head);
    if (QUEUEempty()) {
        head = new;
        head->next = head;
        return;
    }
    node* t;
    for (t = head; head != t->next; t = t->next)
        ;
    t->next = new;
}

int QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval = head->item;
    if (head == head->next) {
        // only one node left in the list
        free(head);
        head = NULL;
        return retval;
    }
    node* t;
    for (t = head; head != t->next; t = t->next)
        ;
    t->next = head->next;
    free(head);
    head = t->next;
    return retval;
}