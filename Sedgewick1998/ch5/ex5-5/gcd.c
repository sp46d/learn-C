#include <stdio.h>
#include <stdlib.h>

// code in the text that uses recursive calls
int gcd(int M, int N)
{
    if (N == 0) {
        return M;
    }
    return gcd(N, M % N);
}

// my code without recursive calls
int my_gcd(int M, int N)
{
    int t = N;
    int s = M;
    int old_t;
    while (t != 0) {
        old_t = t;
        t = s % t;
        s = old_t;
    }
    return s;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: ./gcd <NUMBER> <NUMBER>\n");
        exit(1);
    }
    int M = atoi(argv[1]);
    int N = atoi(argv[2]);
    if (N > M) {
        printf("Error: first number must be greater than second number\n");
        exit(1);
    }
    printf("   gcd(%d, %d) = %d\n", M, N, gcd(M, N));
    printf("my_gcd(%d, %d) = %d\n", M, N, my_gcd(M, N));
    return 0;
}