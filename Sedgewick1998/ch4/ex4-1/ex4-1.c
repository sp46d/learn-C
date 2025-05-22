#include <math.h>
typedef float Item;
#define eq(A, B)                                                               \
    (fabs((A)) - fabs((B)) > 0 ? (fabs((A) - (B)) / fabs((A))) < 1e-6          \
                               : (fabs((A) - (B)) / fabs((B))) < 1e-6)