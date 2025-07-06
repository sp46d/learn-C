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
    printf("%f\n", POLYeval(p, f));
    POLYdestroy(p);
    POLYdestroy(t);
}