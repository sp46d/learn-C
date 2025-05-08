#include <float.h> // for FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
#include <limits.h> // for INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, SHRT_MAX, SHRT_MIN
#include <stdio.h>

int main(void)
{
    int d;
    long int ld;
    short int sd;
    float f;
    double g;
    printf("1. int (%lu bytes): largest = %d, smallest = %d\n", sizeof(d),
        INT_MAX, INT_MIN);
    printf("2. long int (%lu bytes): largest = %ld, smallest = %ld\n",
        sizeof(ld), LONG_MAX, LONG_MIN);
    printf("3. short int (%lu bytes): largest = %d, smallest = %d\n",
        sizeof(sd), SHRT_MAX, SHRT_MIN);
    printf("4. float (%lu bytes): largest = %f, smallest = %f\n", sizeof(f),
        FLT_MAX, FLT_MIN);
    printf("5. double (%lu bytes): largest = %g, smallest = %g\n", sizeof(g),
        DBL_MAX, DBL_MIN);

    return 0;
}