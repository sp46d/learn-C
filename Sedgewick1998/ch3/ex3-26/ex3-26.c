#include "../linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 3 || argc > 5) {
        printf("Usage: ex3-26 N M\n");
        return 1;
    }
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    link x = createlist(N, 1);
    link y = createlist(M, 101);

    printf("before merge:\n");
    printnodes(x);
    printnodes(y);

    insertnode(findnode(x, 5), y);
    printf("\nafter merge:\n");
    printnodes(x);

    // create the first node of circular list x
    // link x1 = malloc(sizeof(*x0));
    // x1->item = 1;
    // x1->next = x1;

    // link x = x1;
    // for (int i = 0; i < N; i++) {
    //     x = (x->next = malloc(sizeof(*x)));
    //     x->item = i;
    //     x->next = x1;
    // }

    // // creat the first node of circular list t
    // link t1 = malloc(sizeof(*t1));
    // t1->item = 101;
    // t1->next = t1;
}