// Exercise 5.28
// Write a function that computes efficiently the number of trailing 0s in the
// binary representation of an integer.

#include <stdio.h>
#include <stdlib.h>

int countzeros(int N, int cnt)
{
    if (N % 2 == 0) {
        return countzeros(N / 2, cnt + 1);
    } else {
        return cnt;
    }
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    printf("number of trailing zeros of %d: %d\n", N, countzeros(N, 0));
    return 0;
}