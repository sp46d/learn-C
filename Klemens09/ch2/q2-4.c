#include "utility_fns.h"
#include <math.h>
#define ARR_SIZE 100

int main(void)
{
    int a[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i)
        a[i] = pow(i + 1, 2);
    print_array(a, ARR_SIZE);
    return 0;
}
