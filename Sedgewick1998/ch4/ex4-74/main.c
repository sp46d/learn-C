#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 4) {
        extern int M;
        M = atoi(argv[3]);
    }

    int N = atoi(argv[1]);
    float f = atof(argv[2]);
    Poly t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
    Poly p = POLYcopy(t);
    Poly q;
    for (int i = 0; i < N; i++) {
        q = POLYcopy(t);
        p = POLYmult(p, q);
    }
    printf("Binomial coefficients:\n");
    showPOLY(p);
    printf("= %f\n", POLYeval(p, f));
    printf("\nDifferentiation:\n");
    Poly d = POLYdiff(p);
    showPOLY(d);
    printf("\n\nIntegration:\n");
    Poly i = POLYintegral(d);
    showPOLY(i);
    printf("\n");
    POLYdestroy(i);
    POLYdestroy(t);
}