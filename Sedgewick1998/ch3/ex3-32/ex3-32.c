#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item;
    int next;
} Node;

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    Node l[N];
    // initialize nodes
    for (int i = 0; i < N - 1; i++) {
        l[i].item = i + 1;
        l[i].next = i + 1;
    }
    l[N - 1].item = N;
    l[N - 1].next = 0;

    int id = 0;
    while (l[id].next != id) {
        for (int i = 1; i < M - 1; i++)
            id = l[id].next;
        l[id].next = l[l[id].next].next;
        id = l[id].next;
    }
    printf("Last one remained: %d\n", l[id].item);
    return 0;
}