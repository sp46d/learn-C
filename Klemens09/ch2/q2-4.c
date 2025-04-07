#include <math.h>
#include <stdio.h>
#define ARR_SIZE 100

void print_array(int in_array[], int array_size);

int main(void)
{
    int a[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i)
        a[i] = pow(i + 1, 2);
    print_array(a, ARR_SIZE);
    return 0;
}

void print_array(int in_array[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        printf("%d squared is %d\n", i + 1, in_array[i]);
}
