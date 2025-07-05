#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    float p = atof(argv[2]);
    Poly t;
    Poly x;
    int i;
    int j;
    printf("Binomial coefficients\n");
    t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
    for (i = 0, x = t; i < N - 1; i++) {
        x = POLYmult(t, x);
    }
    showPOLY(x);
    printf("= %.4f\n", POLYeval(x, p));

    printf("\n2. Add two polynomials\n");
    Poly r = POLYcreate(5, POLYterm(2, 4), POLYterm(-1, 3), POLYterm(12, 2),
        POLYterm(1, 1), POLYterm(-15, 0));
    Poly s = POLYcreate(5, POLYterm(-2, 4), POLYterm(3, 3), POLYterm(-28, 2),
        POLYterm(3, 1), POLYterm(22, 0));
    showPOLY(r);
    printf("+\n");
    showPOLY(s);
    printf("= ");
    showPOLY(POLYadd(r, s));
    printf("\n");
}
