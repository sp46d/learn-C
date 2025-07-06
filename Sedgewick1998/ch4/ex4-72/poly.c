// Array implementation

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

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

float POLYeval(Poly p, float x)
{
    float t = 0.0;
    for (int i = p->N - 1; i >= 0; i--) {
        t = t * x + p->a[i];
    }
    return t;
}