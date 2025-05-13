#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

link createlist(size_t n, int v);
void deletenode(link list, link node);
void insertnode(link list, link node);
void printnodes(link list);
link findlast(link list);
link findnode(link list, int k);

#endif
