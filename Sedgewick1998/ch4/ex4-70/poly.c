// Linked list with null head implementation

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int exp;
    struct poly* next;
};

static Poly FINDNEXT(Poly a, int exp)
{
    if (a->next == NULL) {
        return NULL;
    }

    Poly p;
    for (p = a; p->next != NULL; p = p->next) {
        if (p->next->exp == exp) {
            break;
        }
    }
    return p;
}

Poly POLYterm(int a, int b)
{
    Poly new = malloc(sizeof(struct poly));
    new->coeff = a;
    new->exp = b;
    new->next = NULL;
    return new;
}

Poly POLYadd(Poly a, Poly b)
{
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    } else if (a == NULL && b == NULL) {
        return NULL;
    }

    Poly head = POLYterm(0, 0);
    head->next = a;
    Poly q;
    Poly t;
    for (Poly p = b; p != NULL; p = p->next) {
        q = FINDNEXT(head, p->exp);
        if (q->next != NULL) {
            q->next->coeff += p->coeff;
            if (q->next->coeff == 0) {
                t = q->next;
                q->next = t->next;
                free(t);
            }
        } else {
            q->next = POLYterm(p->coeff, p->exp);
        }
    }
    return a;
}

Poly POLYmult(Poly a, Poly b)
{
    Poly new = NULL;

    for (Poly p = a; p != NULL; p = p->next) {
        for (Poly q = b; q != NULL; q = q->next) {
            new = POLYadd(new, POLYterm(p->coeff * q->coeff, p->exp + q->exp));
        }
    }
    return new;
}

void showPOLY(Poly a)
{
    int maxExp = 0;
    for (Poly t = a; t != NULL; t = t->next) {
        if (t->exp > maxExp) {
            maxExp = t->exp;
        }
    }
    int isfirstterm = 1;
    for (int i = maxExp; i >= 0; i--) {
        for (Poly t = a; t != NULL; t = t->next) {
            if (t->exp == i) {
                if (t->coeff > 0) {
                    if (isfirstterm) {
                        printf("%dx^%d ", t->coeff, i);
                        isfirstterm = 0;
                    } else {
                        printf("+ %dx^%d ", t->coeff, i);
                    }
                } else if (t->coeff < 0) {
                    if (isfirstterm) {
                        printf("%dx^%d ", t->coeff, i);
                        isfirstterm = 0;
                    } else {
                        printf("- %dx^%d ", -1 * t->coeff, i);
                    }
                }
            }
        }
    }
}

double POLYeval(Poly a, double f)
{
    double sum = 0.0;
    for (Poly t = a; t != NULL; t = t->next) {
        int coeff = t->coeff;
        double x = 1.0;
        for (int i = 0; i < t->exp; i++) {
            x = x * f;
        }
        sum = sum + (coeff * x);
    }
    return sum;
}
