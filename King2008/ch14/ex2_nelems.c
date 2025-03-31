#include <stdio.h>
#define NELEMS(a) (sizeof((a)) / sizeof((a)[0]))

int main(void)
{
    int a[][5] = { { 1, 2, 3, 4, 5 }, { 5, 6, 1, 2, 3 }, { 2, 3, 4, 5, 1 } };
    printf("Number of elements of a[] is: %zu\n", NELEMS(a[2]));
    return 0;
}
