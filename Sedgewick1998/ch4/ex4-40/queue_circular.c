// To be a circular list, the next node of the tail should be the head of the
// list. But it doesn't mean that head being equal to tail indicates the list is
// empty. Why? Suppose that there is one node left in the list and both head and
// tail point to this same node. The head is equal to the tail, but the list is
// still not empty. How do we check if the list is empty? Check if either head
// of tail is null.

// With the circular list, I realize I don't have to maintain both head and tail
// nodes. Maintaining only the tail node will do the job, because the next node
// of the tail will be the head of the list. So, QUEUEget() will always return
// the value from the node following the tail node.

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* next;
} node;

static node* head;
static node* tail;

static node* NEW(int x, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->next = next;
    return new;
}

void QUEUEinit(void)
{
    head = NULL;
    tail = NULL;
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(int x)
{
    node* new = NEW(x, head);
    if (QUEUEempty()) {
        head = new;
        tail = new;
        tail->next = head;
        return;
    }
    tail->next = new;
    tail = new;
}

int QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval = head->item;
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
        return retval;
    }
    node* t = head->next;
    tail->next = t;
    free(head);
    head = t;
    return retval;
}