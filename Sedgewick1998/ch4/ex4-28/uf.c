#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

static int* id;
static int* sz;
static int maxN;

void UFinit(int N)
{
    maxN = N;
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
    while (i != id[i]) {
        i = id[i];
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

int UFcount(int p)
{
    int cnt = 0;
    // Not very efficient, because it loops over the entire elements of the
    // array, but it gets the job done.
    for (int i = 0; i < maxN; i++) {
        if (UFfind(p, i)) {
            cnt++;
        }
    }
    // Doesn't count the calling node itself
    return cnt - 1;
}