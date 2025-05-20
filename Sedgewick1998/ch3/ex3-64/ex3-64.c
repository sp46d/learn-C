// Exercise 3.64. Modify Program 3.17 to process input strings individually
// (allocate memory for each string after reading it from the input). You can
// assume that all strings have less than 100 characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 1000
#define Smax 100
// #define Mmax 10000

// char buf[Mmax];
int M = 0;

int compare(const void* i, const void* j)
{
    return strcmp(*(char**)i, *(char**)j);
}

int main(void)
{
    int i;
    int N;
    char* a[Nmax];
    for (N = 0; N < Nmax; N++) {
        a[N] = malloc(Smax);
        if (scanf("%s", a[N]) == EOF) {
            break;
        }
    }
    qsort(a, N, sizeof(char*), compare);
    for (i = 0; i < N; i++) {
        printf("%s\n", a[i]);
        free(a[i]);
    }
}
