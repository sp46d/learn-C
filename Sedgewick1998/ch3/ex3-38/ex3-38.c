// Exercise 3.38. Write a function that takes a link to a list as argument and
// returns a link to a copy of the list (a new list that contains the same
// items, in the same order).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* link;
struct node {
    int item;
    link next;
};

link copy_list(link list)
{
    link new_list = malloc(sizeof(*new_list));
    link t = new_list;
    link x;
    for (x = list; x->next != NULL; x = x->next) {
        t->item = x->item;
        t->next = malloc(sizeof(*t));
        t = t->next;
        t->next = NULL;
    }
    // the item of the last node copied
    t->item = x->item;
    return new_list;
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    link l = malloc(sizeof(*l));
    link x = l;

    srand(time(NULL));
    l->item = rand() % M;
    l->next = NULL;
    for (int i = 1; i < N; i++) {
        x->next = malloc(sizeof(*x));
        x = x->next;
        x->item = rand() % M;
        x->next = NULL;
    }

    printf("before:\n");
    for (link a = l; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");

    link after = copy_list(l);
    printf("after:\n");
    for (link a = after; a != NULL; a = a->next)
        printf("%d ", a->item);
    printf("\n");
    return 0;
}
