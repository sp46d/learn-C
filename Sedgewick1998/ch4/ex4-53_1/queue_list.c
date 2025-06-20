// Implement no-duplicates with a ingnore-the-new-item policy

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    Item item;
    struct node* next;
} node;

static node* head; // most recent item goes to head -> put
static node* tail; // least recent item remains at tail -> get

static node* NEW(Item item, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = item;
    new->next = next;
    return new;
}

static int isin(Item x)
{
    node* t;
    for (t = head; t != NULL; t = t->next) {
        if (eq(t->item, x)) {
            return 1;
        }
    }
    return 0;
}

void QUEUEinit(void)
{
    head = NULL;
    tail = NULL;
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(Item item)
{
    if (isin(item)) {
        return;
    }
    node* new = NEW(item, head);
    if (QUEUEempty()) {
        tail = new;
    }
    head = new;
}

Item QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    Item retval = tail->item;
    if (head == tail) {
        // When only one element left in the list
        free(tail);
        head = NULL;
        tail = NULL;
    } else {
        node* t;
        for (t = head; t->next != tail; t = t->next)
            ;
        t->next = tail->next;
        free(tail);
        tail = t;
    }
    return retval;
}

void QUEUEdump(void)
{
    node* t;
    for (t = head; t != NULL; t = t->next) {
        printf("%c ", t->item);
    }
    printf("\n");
}
