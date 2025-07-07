// Array implementation

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

// Max exponent; terms with exponent greater than or equal to M will be ignored.
// if negative, M does not affect polynomials, so it will behave as before.
int M = -1;

struct poly {
    int N;
    int* a;
};

Poly POLYterm(int coeff, int exp)
{
    int i;
    Poly t = malloc(sizeof(struct poly));
    t->N = exp + 1;
    t->a = malloc((exp + 1) * sizeof(int));
    t->a[exp] = coeff;
    for (int i = 0; i < exp; i++) {
        t->a[i] = 0;
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
    int max_term = M < 0 || p->N - 1 < M ? p->N - 1 : M - 1;

    float t = 0.0;
    for (int i = max_term; i >= 0; i--) {
        t = t * x + p->a[i];
    }
    return t;
}

void showPOLY(Poly p)
{
    int coeff;
    int max_term = M < 0 || p->N - 1 < M ? p->N - 1 : M - 1;
    int isfirstterm = 1;

    for (int i = max_term; i >= 0; i--) {
        if ((coeff = p->a[i])) {
            if (isfirstterm) {
                printf("%d%s%c", coeff, i ? "x^" : "", i ? i + '0' : ' ');
                isfirstterm = 0;
            } else {
                if (coeff > 0) {
                    printf(
                        " + %d%s%c", coeff, i ? "x^" : "", i ? i + '0' : ' ');
                } else {
                    printf(" - %d%s%c", coeff * -1, i ? "x^" : "",
                        i ? i + '0' : ' ');
                }
            }
        }
    }
}