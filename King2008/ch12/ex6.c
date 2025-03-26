// Exercise 6. Rewrite the following function to use pointer arithmetic instead
// of array subscripting. (In other words, eliminate the variable i and all uses
// of the [] operator.) Make as few changes as possible.

#include <stdio.h>

int old_sum_array(const int a[], int n);
int new_sum_array(const int* a, int n);

int main(void)
{
    int a[] = { 1, 2, 3, 4, 5 };
    printf("Old sum: %d\n", old_sum_array(a, 5));
    printf("New sum: %d\n", new_sum_array(a, 5));
}

int old_sum_array(const int a[], int n)
{
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int new_sum_array(const int a[], int n)
{
    int sum;
    const int* p;

    sum = 0;
    for (p = a; p < a + n; p++)
        sum += *p;
    return sum;
}
