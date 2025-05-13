#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

link createlist(size_t n, int v)
{
    link first = malloc(sizeof(*first));
    link x = first;
    first->item = v;
    first->next = first;

    // a circular list
    for (int i = v + 1; i < v + n; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = first;
    }
    return first;
}

void deletenode(link list, link node)
{
    link x;
    for (x = list; node != x->next; x = x->next) {
        if (list == x->next) {
            printf("Error: the received node cannot be found in the list\n");
            return;
        }
    }
    link node_to_be_deleted = x->next;
    x->next = x->next->next;
    free(node_to_be_deleted);
}

void insertnode(link list, link node)
{
    link x = list->next;
    list->next = node;
    // in case where there are more than one node to be inserted
    link y = node;
    for (; node != y->next; y = y->next)
        ;
    y->next = x;
}

void printnodes(link list)
{
    link x = list;
    do {
        printf("%d ", x->item);
        x = x->next;
    } while (list != x);
    printf("\n");
}

link findlast(link list)
{
    link x;
    for (x = list; list != x->next; x = x->next)
        ;
    return x;
}

link findnode(link list, int k)
{
    for (int i = 0; i < k; i++) {
        list = list->next;
    }
    return list;
}