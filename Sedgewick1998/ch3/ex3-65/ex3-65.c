#include <stdio.h>
#include <stdlib.h>

int** malloc2d(int r, int c)
{
    int** out = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        out[i] = malloc(c * sizeof(int));
    }
    return out;
}

int is_gcd_one(int n, int m)
{
    if (n == 0 || m == 0) {
        return 0;
    }
    int gcd;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((n % i == 0) && (m % j == 0) && (i == j)) {
                gcd = i;
            }
        }
    }

    if (gcd == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]); // number of rows
    int M = atoi(argv[2]); // number of columns

    int** a = malloc2d(N, M); // array of size [N][M]
    // store results of is_gcd_one() in a
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = is_gcd_one(i, j);
        }
    }

    // print results
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}