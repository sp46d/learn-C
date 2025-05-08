#include "randnum.h"
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

    srand(time(NULL)); // feed the random seed to the random number generator
    for (int i = 0; i < sizeof(rs) / sizeof(rs[0]); i++) {
        r = rs[i];
        for (int j = 0; j < sizeof(Ns) / sizeof(Ns[0]); j++) {
            N = Ns[j];
            m1 = 0.0;
            m2 = 0.0;
            for (int i = 0; i < N; i++) {
                Number d = randnum(0, r);
                m1 += (float)d / N;
                m2 += ((float)d * d) / N;
            }
            printf("r = %d, N = %d: Average = %f, Std. Dev. = %g\n", r, N, m1,
                sqrt(m2 - m1 * m1));
        }
    }
    return 0;
}
