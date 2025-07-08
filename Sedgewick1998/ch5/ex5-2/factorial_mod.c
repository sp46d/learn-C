#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int factorial_mod(int N, int M)
{
    if (N == 1) {
        return 1;
    }
    long out = (N % M) * factorial_mod(N - 1, M);
    return (int)(out % M);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: ./main <NUMBER> <NUMBER>\n");
        exit(1);
    }
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    printf("> %d\n", factorial_mod(N, M));
    return 0;
}