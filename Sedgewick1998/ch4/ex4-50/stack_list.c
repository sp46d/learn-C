// Implement no-duplicates using the ignore-the-new-item policy

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    Item item;
    struct node* next;
} node;

static node* head;
static int n_elements;

static node* NEW(Item x, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->next = next;
    return new;
}

void STACKinit(void)
{
    head = NULL;
    n_elements = 0;
}

int STACKempty(void) { return head == NULL; }

void STACKpush(Item x)
{
    node* t;
    for (t = head; t != NULL; t = t->next) {
        if (eq(t->item, x)) {
            printf("Warning: Duplicate item already exist in the list\n");
            return;
        }
    }
    node* new = NEW(x, head);
    head = new;
    n_elements++;
}

Item STACKpop(void)
{
    if (STACKempty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int retval = head->item;
    node* t = head->next;
    free(head);
    head = t;
    n_elements--;
    return retval;
}

char* STACKdump(void)
{
    char* out = malloc((n_elements + 1) * sizeof(*out));
    node* t;
    int i;
    for (t = head, i = n_elements - 1; t != NULL; t = t->next, i--) {
        out[i] = t->item;
    }
    out[n_elements] = '\0';
    return out;
}
