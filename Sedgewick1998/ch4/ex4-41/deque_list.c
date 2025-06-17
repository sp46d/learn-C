#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* prev;
    struct node* next;
} node;

static node* head;
static node* tail;

static node* NEW(int x, node* prev, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->prev = prev;
    new->next = next;
    return new;
}

void DEQUEinit(void)
{
    head = NULL;
    tail = NULL;
}

void DEQUEpush_l(int x)
{
    node* new = NEW(x, NULL, head);
    if (DEQUEempty()) {
        head = new;
        tail = new;
        return;
    }
    head->prev = new;
    head = new;
}

int DEQUEpop_l(void)
{
    if (DEQUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval = head->item;

    if (head == tail) {
        // only one item left in the list
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        node* t = head->next;
        t->prev = NULL;
        free(head);
        head = t;
    }
    return retval;
}

void DEQUEpush_r(int x)
{
    node* new = NEW(x, tail, NULL);
    if (DEQUEempty()) {
        head = new;
        tail = new;
        return;
    }
    tail->next = new;
    tail = new;
}

int DEQUEpop_r(void)
{
    if (DEQUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval = tail->item;

    if (head == tail) {
        // only one item left in the list
        free(tail);
        head = NULL;
        tail = NULL;
    } else {
        node* t = tail->prev;
        t->next = NULL;
        free(tail);
        tail = t;
    }
    return retval;
}

int DEQUEempty(void) { return head == NULL; }

void DEQUEdump(void)
{
    node* t = head;
    while (t != NULL) {
        printf("%c ", t->item);
        t = t->next;
    }
    printf("\n");
}
