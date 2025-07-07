// Array implementation

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
    int N;
    float* a;
};

Poly POLYterm(float coeff, int exp)
{
    int i;
    Poly t = malloc(sizeof(struct poly));
    t->N = exp + 1;
    t->a = malloc((exp + 1) * sizeof(float));
    t->a[exp] = coeff;
    for (int i = 0; i < exp; i++) {
        t->a[i] = 0.0f;
    }
    return t;
}

Poly POLYcopy(Poly src)
{
    if (src == NULL) {
        printf("Error: Null pointer is given to argument\n");
        return NULL;
    }
    Poly t = malloc(sizeof(*t));
    t->N = src->N;
    t->a = malloc(src->N * sizeof(int));
    int i;
    int j;
    for (i = 0; i < src->N; i++) {
        t->a[i] = src->a[i];
    }
    return t;
}

void POLYdestroy(Poly p)
{
    free(p->a);
    free(p);
}

Poly POLYadd(Poly p, Poly q)
{
    if (p == NULL) {
        Poly r = POLYcopy(q);
        POLYdestroy(q);
        return r;
    } else if (q == NULL) {
        Poly r = POLYcopy(p);
        POLYdestroy(p);
        return r;
    } else if (p == NULL && q == NULL) {
        return NULL;
    }

    Poly r = POLYterm(0, p->N > q->N ? p->N - 1 : q->N - 1);
    for (int i = 0; i < p->N; i++) {
        r->a[i] += p->a[i];
    }
    POLYdestroy(p);
    for (int j = 0; j < q->N; j++) {
        r->a[j] += q->a[j];
    }
    POLYdestroy(q);
    return r;
}

Poly POLYsubtract(Poly p, Poly q)
{
    return POLYadd(p, POLYmult(POLYterm(-1, 0), q));
}

Poly POLYmult(Poly p, Poly q)
{
    Poly r = POLYterm(0, (p->N - 1) + (q->N - 1));
    for (int i = 0; i < p->N; i++) {
        for (int j = 0; j < q->N; j++) {
            r->a[i + j] += p->a[i] * q->a[j];
        }
    }
    POLYdestroy(p);
    POLYdestroy(q);
    return r;
}

Poly POLYdiv(Poly p, Poly q)
{
    // Poly POLYdiv(Poly p, Poly q): Performs polynomial division on
    // Polynomial p (dividend) by Polynomial q (divisor) and returns quotient.
    // This function ignores resulting remainder. For remainder, see POLYmod
    // below.
    if (p->N < q->N) {
        printf(
            "Error: Exponent of divisor is greater than exponent of dividend. "
            "Returning NULL pointer.\n");
        return NULL;
    }
    Poly r = POLYterm(0, (p->N - 1) - (q->N - 1));
    int exp = q->N - 1;
    Poly t = POLYcopy(p);
    Poly s;
    Poly divisor;
    for (int i = p->N - 1; i >= exp; i--) {
        divisor = POLYcopy(q);
        r->a[i - exp] = t->a[i] / divisor->a[exp];
        s = POLYterm(t->a[i] / divisor->a[exp], i - exp);
        t = POLYsubtract(t, POLYmult(divisor, s));
    }
    POLYdestroy(t);
    POLYdestroy(p);
    POLYdestroy(q);
    return r;
}

Poly POLYmod(Poly p, Poly q)
{
    // Poly POLYmod(Poly p, Poly q): Returns remainder after performing
    // polynomial division on p by q. This function ignores resulting quotient.
    // For quotient, see POLYdiv above.
    Poly quotient = POLYdiv(POLYcopy(p), POLYcopy(q));
    return POLYsubtract(p, POLYmult(quotient, q));
}

Poly POLYcomp(Poly p, Poly q)
{
    // Poly POLYcomp(Poly p, Poly q): Performs a polynomial composition of two
    // polynomials p and q and returns the resulting polynomial after
    // composition. Polynomial q goes inside polynomial p. For example, if p =
    // x^2 + 1 and q = x + 1, then POLYcomp(p, q) will return (x + 1)^2 + 1.
    // The function destroys polynomials p and q passed to the function as
    // arguments.
    Poly s;
    Poly t;
    Poly r = NULL;
    for (int i = 0; i < p->N; i++) {
        s = POLYterm(p->a[i], 0);
        for (int j = 0; j < i; j++) {
            t = POLYcopy(q);
            s = POLYmult(s, t);
        }
        r = POLYadd(r, s);
    }
    return r;
}

Poly POLYintegral(Poly p)
{
    // Poly POLYintegral(Poly): Performs integration on the polynomial passed to
    // the function as agrument. It destroys the argument and returns a newly
    // created polynomials where its coefficients and exponents are results of
    // integration. The resulting polynomial has its constant term (i.e. x^0)
    // set to 0.
    Poly r = POLYterm(0, p->N);
    for (int i = 0; i < p->N; i++) {
        r->a[i + 1] = p->a[i] / (i + 1);
    }
    POLYdestroy(p);
    return r;
}

Poly POLYdiff(Poly p)
{
    // Poly POLYdiff(Poly): Performs differentiation on the polynomial passed to
    // the function as argument. It destroys the argument and returns a newly
    // created polynomial where its coefficients and exponents are results of
    // differentiation.
    Poly r = POLYterm(0, p->N - 2);
    for (int i = 0; i < r->N; i++) {
        r->a[i] = p->a[i + 1] * (i + 1);
    }
    POLYdestroy(p);
    return r;
}

float POLYeval(Poly p, float x)
{
    float t = 0.0;
    for (int i = p->N - 1; i >= 0; i--) {
        t = t * x + p->a[i];
    }
    return t;
}

void showPOLY(Poly p)
{
    float coeff;
    int isfirstterm = 1;

    for (int i = p->N - 1; i >= 0; i--) {
        if ((coeff = p->a[i])) {
            if (isfirstterm) {
                printf("%.2f%s%c", coeff, i ? "x^" : "", i ? i + '0' : ' ');
                isfirstterm = 0;
            } else {
                if (coeff > 0) {
                    printf(
                        " + %.2f%s%c", coeff, i ? "x^" : "", i ? i + '0' : ' ');
                } else {
                    printf(" - %.2f%s%c", coeff * -1, i ? "x^" : "",
                        i ? i + '0' : ' ');
                }
            }
        }
    }
}