#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int sz;
} node;

struct uf {
    node* set;
    int maxN;
};

static int find(Uf a, int x)
{
    if (x > a->maxN) {
        return -1;
    }
    int i;
    for (i = x; a->set[i].id != i; i = a->set[i].id)
        ;
    return i;
}

Uf UFinit(int N)
{
    Uf a = malloc(sizeof(*a));
    a->maxN = N;
    a->set = malloc((N + 1) * sizeof(*(a->set)));
    for (int i = 0; i < N; i++) {
        a->set[i].id = i;
        a->set[i].sz = 1;
    }
    return a;
}

int UFfind(Uf x, int a, int b)
{
    if (find(x, a) < 0 || find(x, b) < 0) {
        return -1;
    }
    return find(x, a) == find(x, b);
}

void UFunion(Uf x, int a, int b)
{
    if (UFfind(x, a, b) > 0 || UFfind(x, a, b) == -1) {
        return;
    }
    int id_a = find(x, a);
    int id_b = find(x, b);

    if (x->set[id_a].sz > x->set[id_b].sz) {
        x->set[id_b].id = x->set[id_a].id;
        x->set[id_a].sz += x->set[id_b].sz;
    } else {
        x->set[id_a].id = x->set[id_b].id;
        x->set[id_b].sz += x->set[id_a].sz;
    }
}
