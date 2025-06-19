// Implement no-duplicates using the forget-the-old-item policy

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
    node* new = NEW(x, head);
    if (!STACKempty()) {
        if (eq(head->item, x)) {
            new->next = head->next;
            free(head);
            n_elements--;
        } else {
            node* t;
            for (t = head; t->next != NULL; t = t->next) {
                if (eq(t->next->item, x)) {
                    node* s = t->next;
                    t->next = s->next;
                    free(s);
                    n_elements--;
                    break;
                }
            }
        }
    }
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
