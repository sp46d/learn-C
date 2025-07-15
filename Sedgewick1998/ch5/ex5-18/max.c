// Exercise 5.18
// Modify the divide-and-conquer program for finding the maximum element in an
// array (Program 5.6) to divide an array of size N into one part of size
// k = 2 ^ (ceil(lgN) - 1) and another of size N - k (so that the size of at
// least one of the parts is a power of 2).

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Program 5.6 (except that I use type int instead of Item)
int old_max(int a[], int l, int r)
{
    int u;
    int v;
    int m = (l + r) / 2;
    if (l == r) {
        return a[l];
    }
    u = old_max(a, l, m);
    v = old_max(a, m + 1, r);
    return u > v ? u : v;
}

int new_max(int a[], int l, int r)
{
    if (l == r) {
        return a[l];
    }
    // d can get as low as 1, never get to 0
    int d = pow(2, ceil(log2(r - l + 1)) - 1);
    int u = new_max(a, l, l + d - 1);
    int v = new_max(a, l + d, r);
    return u > v ? u : v;
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    srand(time(NULL));
    int a[N];
    int d;
    printf("Random numbers:\n>");
    for (int i = 0; i < N; i++) {
        d = rand() % 100;
        a[i] = d;
        printf(" %d", d);
    }
    printf("\n\n");

    printf("old_max(a[]) = %d\n", old_max(a, 0, N - 1));
    printf("new_max(a[]) = %d\n", new_max(a, 0, N - 1));
}