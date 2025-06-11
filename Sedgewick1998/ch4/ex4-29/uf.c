#include "uf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int sz;
} Item;

static Item* items;

void UFinit(int N)
{
    items = malloc(N * sizeof(*items));
    for (int i = 0; i < N; i++) {
        items[i].id = i;
        items[i].sz = 1;
    }
}

static int find(int p)
{
    int i = p;
    while (items[i].id != i) {
        i = items[i].id;
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
    if (items[i].sz > items[j].sz) {
        items[j].id = i;
        items[i].sz += items[j].sz;
    } else {
        items[i].id = j;
        items[j].sz += items[i].sz;
    }
}
