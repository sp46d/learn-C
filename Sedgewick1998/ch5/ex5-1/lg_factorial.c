#include <math.h>

double lg_factorial(int N)
{
    if (N == 1) {
        return 0;
    }
    return log2(N) + lg_factorial(N - 1);
}