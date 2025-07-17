// Exercise 5.25
// Write a recursive program that fills in an n-by-2^n array with 0s and 1s such
// that the array represents all the n-bit binary numbers, as depicted in
// Figure 5.9.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int** a;

void binaryinit(int N)
{

    int ncol = pow(2, N);
    // allocate memory to a
    a = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        a[i] = malloc(ncol * sizeof(int));
    }
    // initialize a to 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < ncol; j++) {
            a[i][j] = 0;
        }
    }
}

//    [0 1 2 3 4 5 6 7]
// [0] 1 1 1 1 0 0 0 0
// [1] 1 1 0 0 1 1 0 0
// [2] 1 0 1 0 1 0 1 0

// (2, 0, 4)
// row = 0, m = 2, a[0, 0:1] = 1; => row = 1 (2, 0, 2) => (2, 2, 4)
// row = 1, m = 1, a[1, 0] = 1; => row = 2 (2, 0, 1) => (2, 1, 2)
// row = 2, m = 0, return;
// row = 2, m = 1, return;
// row = 1, m = 3, a[1, 2] = 1; => row = 2 (2, 2, 3)

void createbinary(int N, int row, int l, int r)
{
    int m = (l + r) / 2;
    if (row < N) {
        for (int i = l; i < m; i++) {
            a[row][i] = 1;
        }
        createbinary(N, row + 1, l, m);
        createbinary(N, row + 1, m, r);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("usage: ./binary <number of digits>\n");
        exit(1);
    }
    int N = atoi(argv[1]);
    binaryinit(N);
    createbinary(N, 0, 0, pow(2, N));

    for (int i = pow(2, N) - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    // printf("\n");
}