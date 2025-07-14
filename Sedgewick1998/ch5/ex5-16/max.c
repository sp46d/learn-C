// Exercise 5.16
// Write a recursive program that finds the maximum element in an array, based
// on comparing the first element in the array against the maximum element in
// the rest of the array (computed recursively).

#include <stdio.h>
#include <stdlib.h>

int findmax(int* a, size_t len)
{
    int firstelem = a[0];
    if (len == 1) {
        return firstelem;
    }
    int maxrest = findmax(&a[1], len - 1);
    return firstelem > maxrest ? firstelem : maxrest;
}

int main(void)
{
    int a[] = { 1, 2, 3, 4, 5, 6, 10, 8, 7, 20, 18, 100 };
    size_t len = sizeof(a) / sizeof(a[0]);
    printf("> %d\n", findmax(a, len));
}
