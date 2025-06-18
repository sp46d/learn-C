// This program generates 10,000 random numbers ranging from 0 to N-1 and draws
// histogram of the results to see how the generated numbers are distributed.
// This program is written as part of Exercise 4.42 to ensure that rand()
// generate random numbers with equal probability.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N = 25;

int main(void)
{
    srand(time(NULL));
    int r;
    int a[N];
    // initialize array
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }
    // generate random numbers and count how many times the given number is
    // generated; the counts are then stored in array, a[].
    for (int i = 0; i < 100000; i++) {
        r = rand() % N;
        a[r]++;
    }
    // print out the histogram of the results
    for (int i = 0; i < N; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < (a[i] / 150); j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
