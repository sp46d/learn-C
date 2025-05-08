#include "randfloat.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int rs[] = { 10, 100, 1000 };
    int Ns[] = { 1e3, 1e4, 1e5, 1e6 };
    int r;
    int N;
    float m1;
    float m2;
    int x;

    srand(time(NULL));
    for (int i = 0; i < sizeof(rs) / sizeof(rs[0]); i++) {
        r = rs[i];
        for (int j = 0; j < sizeof(Ns) / sizeof(Ns[0]); j++) {
            N = Ns[j];
            m1 = 0.0;
            m2 = 0.0;
            for (int k = 0; k < N; k++) {
                x = randfloat() * r;
                m1 += (float)x / N;
                m2 += ((float)(x * x)) / N;
            }
            printf("r = %d, N = %d: Average = %f, Std. Dev. = %g\n", r, N, m1,
                sqrt(m2 - m1 * m1));
        }
    }
    return 0;
}