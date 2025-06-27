#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    Complex item;
    struct node* next;
} Node;

struct stack {
    Node* top;
    int n_items;
};

static Node* NEW(Complex item, Node* next)
{
    Node* new = malloc(sizeof(*new));
    new->item = item;
    new->next = next;
    return new;
}

Stack STACKinit(void)
{
    Stack new = malloc(sizeof(struct stack));
    new->top = NULL;
    new->n_items = 0;
    return new;
}

int STACKempty(Stack s) { return s->n_items == 0; }

void STACKpush(Stack s, Complex x)
{
    if (!STACKempty(s)) {
        Node* new = NEW(x, s->top);
        s->top = new;
    } else {
        s->top = NEW(x, NULL);
    }
    s->n_items++;
}

Complex STACKpop(Stack s)
{
    Complex retval = s->top->item;
    Node* t = s->top->next;
    free(s->top);
    s->top = t;
    return retval;
}

void STACKdestroy(Stack s)
{
    Node* t1 = s->top;
    Node* t2;
    while (t1 != NULL) {
        t2 = t1->next;
        free(t1);
        t1 = t2;
    }
    free(s);
}
