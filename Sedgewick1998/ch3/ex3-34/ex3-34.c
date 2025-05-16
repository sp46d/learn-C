// Write a function that moves the largest item on a given list to be the final
// node on the list.

// For this problem, I assume we use a "Head pointer, null tail" list, mentioned
// in the book p. 101.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

void move_largest_to_last(link t)
{
    // if the list has only one node in it, do nothing.
    if (t->next == NULL)
        return;

    link max_node = t;
    for (link x = t->next; x != NULL; x = x->next) {
        if (max_node->item < x->item)
            max_node = x;
    }
    // If the largest node happens to be the last node,
    // do nothing.
    if (max_node->next == NULL)
        return;

    link x = t;
    while (x->next != NULL) {
        if (x->next == max_node)
            x->next = max_node->next;
        x = x->next;
    }
    max_node->next = NULL;
    x->next = max_node;
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    link t = malloc(sizeof(*t));
    link x = t;

    srand(time(NULL));
    t->item = rand() % M;
    t->next = NULL;
    for (int i = 1; i < N; i++) {
        x->next = malloc(sizeof(*x));
        x = x->next;
        x->item = rand() % M;
        x->next = NULL;
    }

    printf("before:\n");
    for (link a = t; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");

    move_largest_to_last(t);
    printf("after:\n");
    for (link a = t; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");
}