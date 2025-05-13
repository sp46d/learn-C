#include <stdio.h>

typedef struct node* list;
struct node {
    int item;
    list next;
};

size_t len_list(list node)
{
    size_t n = 1;
    list x = node;
    while (node != x->next) {
        x = x->next;
        n++;
    }
    return n;
}