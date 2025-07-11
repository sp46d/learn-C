#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

static int* id;
static int* sz;

void UFinit(int N)
{
    id = malloc(N * sizeof(*id));
    sz = malloc(N * sizeof(*sz));
    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

static int find(int p)
{
    int i = p;
    while (id[i] != i) {
        i = id[id[i]];
    }
    return i;
}

int UFfind(int p, int q) { return find(p) == find(q); }
void UFunion(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j) {
        return;
    }
    if (sz[i] > sz[j]) {
        id[j] = i;
        sz[i] += sz[j];
    } else {
        id[i] = j;
        sz[j] += sz[i];
    }
}

int UFunionfind(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j) {
        return 1;
    }

    if (sz[i] > sz[j]) {
        id[j] = i;
        sz[i] += sz[j];
    } else {
        id[i] = j;
        sz[j] += sz[i];
    }
    return 0;
}