#include <stdio.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

size_t lenab(link a, link b)
{
    size_t n1 = 0;
    for (link x = a; b != x->next; x = x->next)
        n1++;
    size_t n2 = 0;
    for (link x = b; a != x->next; x = x->next)
        n2++;
    return n1 > n2 ? n2 : n1;
}