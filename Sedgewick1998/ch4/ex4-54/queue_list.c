// Implement no-duplicate queue with a forget-the-old-item policy, which uses
// constant time for put and get.

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* prev;
    struct node* next;
} node;

static node* head; // most recent item goes to head -> put
static node* tail; // least recent item remains at tail -> get
static node** id_table;

static node* NEW(int item, node* prev, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = item;
    new->prev = prev;
    new->next = next;
    return new;
}

void QUEUEinit(int M)
{
    head = NULL;
    tail = NULL;
    id_table = malloc(M * sizeof(node*));
    for (int i = 0; i < M; i++) {
        id_table[i] = NULL;
    }
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(int item)
{
    node* old = id_table[item];
    if (old != NULL) {
        if (old == head) {
            node* t = old->next;
            t->prev = NULL;
            free(old);
            head = t;
        } else if (old == tail) {
            node* t = old->prev;
            t->next = NULL;
            free(old);
            tail = t;
        } else {
            old->prev->next = old->next;
            old->next->prev = old->prev;
            free(old);
        }
        id_table[item] = NULL;
    }
    node* new = NEW(item, NULL, head);
    if (QUEUEempty()) {
        tail = new;
    } else {
        head->prev = new;
    }
    head = new;
    id_table[item] = new;
}

int QUEUEget(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int retval = tail->item;
    if (head == tail) {
        // When only one element left in the list
        free(tail);
        head = NULL;
        tail = NULL;
    } else {
        node* t = tail->prev;
        t->next = NULL;
        free(tail);
        tail = t;
    }
    id_table[retval] = NULL;
    return retval;
}

void QUEUEdump(void)
{
    node* t;
    for (t = tail; t != NULL; t = t->prev) {
        printf("%c ", t->item);
    }
    printf("\n");
}
