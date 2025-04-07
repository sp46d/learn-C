#include "utility_fns.h"
#include <stdio.h>

void print_array(int in_array[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        printf("%d squared is %d\n", i + 1, in_array[i]);
}
