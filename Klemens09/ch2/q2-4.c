#include <math.h>
#include <stdio.h>
#define ARR_SIZE 100

int main(void)
{
    int a[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i) {
        a[i] = pow(i + 1, 2);
        printf("%d squared is %d\n", i + 1, a[i]);
    }
    return 0;
}
