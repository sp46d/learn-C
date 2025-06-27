#include "complex.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct complex {
    int re;
    int im;
};

Complex COMPLEXinit(int r, int i)
{
    Complex new = malloc(sizeof(struct complex));
    new->re = r;
    new->im = i;
    return new;
}

int Re(Complex x) { return x->re; }

int Im(Complex x) { return x->im; }

Complex COMPLEXadd(Complex a, Complex b)
{
    return COMPLEXinit(Re(a) + Re(b), Im(a) + Im(b));
}

Complex COMPLEXmult(Complex a, Complex b)
{
    return COMPLEXinit(
        Re(a) * Re(b) - Im(a) * Im(b), Re(a) * Im(b) + Im(a) * Re(b));
}

void COMPLEXprint(Complex x)
{
    printf("%d", Re(x));
    if (Im(x) >= 0) {
        printf("+%di", Im(x));
        return;
    }
    printf("%di", Im(x));
}
