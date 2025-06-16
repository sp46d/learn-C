#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* next;
} node;

static node* head;
static node* tail;

void QUEUEinit(void)
{
    head = NULL;
    tail = NULL;
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(int x)
{
    node* new = malloc(sizeof(*new));
    if (new == NULL) {
        QUEUEerror();
        return;
    }
    new->item = x;
    new->next = NULL;
    if (QUEUEempty()) {
        head = new;
        tail = new;
        return;
    }
    tail->next = new;
    tail = new;
}

int QUEUEget(void)
{
    if (QUEUEempty()) {
        QUEUEerror();
        return -1;
    }
    int value = head->item;
    node* tmp = head->next;
    free(head);
    head = tmp;
    return value;
}

void QUEUEerror(void)
{
    if (QUEUEempty()) {
        printf("Error: Queue is empty. Can't get a value from the queue\n");
    } else {
        printf("Error: No more memory available for the given value\n");
    }
}
