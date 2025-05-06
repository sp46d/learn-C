#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 1000
#define N 1000

unsigned int random_uint(int min, int max);
int isin(unsigned int a[], int size, int v);

int main(void)
{
    unsigned int r[M];
    srand(time(NULL));
    for (int i = 0; i < M; i++)
        r[i] = random_uint(0, 10e5);

    unsigned int v;
    size_t count = 0;
    clock_t start_time;
    clock_t end_time;
    double time_taken;

    start_time = clock();
    for (int i = 0; i < N; i++) {
        v = random_uint(0, 10e5);
        if (isin(r, M, v) != -1)
            count++;
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("%zu out of %d integers match one of %d integers.\n", count, N, M);
    printf("It took %g seconds.\n", time_taken);
    return 0;
}

unsigned int random_uint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int isin(unsigned int a[], int size, int v)
{
    for (int i = 0; i < size; i++)
        if (a[i] == v)
            return i;
    return -1;
}