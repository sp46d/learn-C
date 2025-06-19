// Exercise 4.51:
// Develop a pushdown-stack implementation that disallows duplicates, using a
// forget-the-old-item policy for integer items between 0 and M-1, and that uses
// constant time for both push and pop.
// Hint: Use a doubly linked list representation for the stack and keep pointers
// to nodes, rather than 0-1 values, in an item-indexed array.

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* prev;
    struct node* next;
} node;

static node* head;
static int n_elements;
static node** id_table;

static node* NEW(int x, node* prev, node* next)
{
    node* new = malloc(sizeof(*new));
    new->item = x;
    new->prev = prev;
    new->next = next;
    return new;
}

void STACKinit(int M)
{
    head = NULL;
    n_elements = 0;
    id_table = malloc(M * sizeof(node*));
    for (int i = 0; i < M; i++) {
        id_table[i] = NULL;
    }
}

int STACKempty(void) { return head == NULL; }

void STACKpush(int x)
{
    node* new = NEW(x, NULL, head);
    if (!STACKempty()) {
        head->prev = new;
        if (head->item == x) {
            new->next = head->next;
            if (head->next != NULL) {
                head->next->prev = new;
            }
            free(head);
            n_elements--;
        } else if (id_table[x] != NULL) {
            node* t = id_table[x];
            t->prev->next = t->next;
            if (t->next != NULL) {
                t->next->prev = t->prev;
            }
            free(t);
            n_elements--;
        }
    }
    head = new;
    n_elements++;
    id_table[x] = new;
}

int STACKpop(void)
{
    if (STACKempty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int retval = head->item;
    node* t = head->next;
    if (t != NULL) {
        t->prev = head->prev;
    }
    free(head);
    head = t;
    n_elements--;
    id_table[retval] = NULL;
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
