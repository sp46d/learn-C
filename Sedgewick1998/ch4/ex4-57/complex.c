#include "complex.h"
#include <stdlib.h>

struct complex {
    float Re;
    float Im;
};

Complex COMPLEXinit(float r, float i)
{
    Complex new = malloc(sizeof(*new));
    new->Re = r;
    new->Im = i;
    return new;
}

float Re(Complex x) { return x->Re; }

float Im(Complex x) { return x->Im; }

Complex COMPLEXadd(Complex a, Complex b)
{
    return COMPLEXinit(Re(a) + Re(b), Im(a) + Im(b));
}

Complex COMPLEXmult(Complex a, Complex b)
{
    return COMPLEXinit(
        Re(a) * Re(b) - Im(a) * Im(b), Re(a) * Im(b) + Im(a) * Re(b));
}
