#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char* argv[])
{
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
    printf("\nDivision:\n");
    Poly d = POLYdiv(POLYcopy(p), POLYterm(1, 1));
    showPOLY(d);
    printf("\n");
    printf("\nMod:\n");
    Poly m = POLYmod(POLYcopy(p), POLYterm(1, 1));
    showPOLY(m);
    printf("\n");
    printf("\nComposition with (x + 1):\n");
    Poly c = POLYcomp(p, POLYadd(POLYterm(1, 1), POLYterm(1, 0)));
    showPOLY(c);
    printf("\n");
    POLYdestroy(c);
    POLYdestroy(m);
}