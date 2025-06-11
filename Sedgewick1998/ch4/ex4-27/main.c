#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    int p;
    int q;
    UFinit(N);
    while (scanf("%d %d", &p, &q) == 2) {
        if (!UFunionfind(p, q)) {
            printf("> %d %d added\n", p, q);
        }
    }
    return 0;
}