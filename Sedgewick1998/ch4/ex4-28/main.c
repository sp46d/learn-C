#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int p;
    int q;
    int N = atoi(argv[1]);
    UFinit(N);
    while (scanf("%d %d", &p, &q) == 2) {
        if (!UFfind(p, q)) {
            UFunion(p, q);
            printf("> %d %d added\n", p, q);
        }
        if (p == q) {
            printf("> Number of nodes connected to %d: %d\n", p, UFcount(p));
        }
    }
    return 0;
}