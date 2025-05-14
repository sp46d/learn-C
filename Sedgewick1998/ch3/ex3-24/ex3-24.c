#include <stdio.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

size_t len_list(link node)
{
    size_t n = 1;
    link x = node;
    while (node != x->next) {
        x = x->next;
        n++;
    }
    return n;
}