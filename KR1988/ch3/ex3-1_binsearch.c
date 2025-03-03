// Exercise 3-1. Our binary search makes two tests inside the loop, when one
// would suffice (at the price of more tests outside) Write a version with only
// one test inside the loop and measure the difference in run-time.

#include <stdio.h>

#define MAX 1000

int binsearch(int x, int v[], int n);

int array[MAX];

int main(void)
{
    // populate the array
    for (int i = 0; i < MAX; i++)
        array[i] = i + 1;

    int n;
    printf("Enter a number (1 - 1000): ");
    scanf("%d", &n);
    int idx = binsearch(n, array, MAX);
    if (idx == -1) {
        printf("Didn't find the received number %d in array.\n", n);
        return 1;
    }
    printf("The received number %d is at %d.\n", n, binsearch(n, array, MAX));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    // while (low <= high) {
    //     mid = (low + high) / 2; // 49, 25, 38, 32, 36, 35, 34, 33
    //     if (x < v[mid])
    //         high = mid; // high = 50, 39, 37, 36, 34,
    //     else if (x > v[mid])
    //         low = mid; // low = 26, 33
    //     else
    //         return mid;
    // }

    while (v[(mid = (low + high) / 2)] != x && low <= high) {

        if (x < v[mid])
            high = mid;
        else
            low = mid;
    }

    if (v[mid] == x)
        return mid;

    return -1;
}
