// Exercise 5.22
// Write a recursive program that computes the length of the ith mark in a ruler
// with 2^n - 1 marks.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// if ruler:
// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1

int lenmark(int i, int l, int r)
{
    // finds the length of ith mark
    static int len = 0;
    if (i == l) {
        return len;
    }
    int m = (r + l + 1) / 2;
    if (i < m) {
        len++;
        return lenmark(i, l, m - 1);
    } else if (i > m) {
        len++;
        return lenmark(i, m, r);
    } else {
        return len;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("usage: ./ruler <Which Mark> <Number of Marks>\n");
        exit(1);
    }
    int i = atoi(argv[1]);
    int N = atoi(argv[2]);
    int exp = ceil(log2(N));

    printf("Length of %d-th mark = %d\n", i, exp - lenmark(i, 0, N));
    return 0;
}