#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int p;
    int q;
    Uf a = UFinit(10);
    Uf b = UFinit(100);
    while (scanf("%d %d", &p, &q) == 2) {
        if (UFfind(a, p, q) > 0) {
            printf("> %d and %d are connected\n", p, q);
        } else if (UFfind(a, p, q) == 0) {
            UFunion(a, p, q);
            printf("> %d, %d added\n", p, q);
        } else {
            printf("Error: Received numbers are out of bounds\n");
        }
    }
    return 0;
}
