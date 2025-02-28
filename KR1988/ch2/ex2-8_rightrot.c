// Exercise 2-8. Write a function rightrot(x, n) that returns the value of the
// integer x rotated to the right by n positions.

#include <math.h>
#include <stddef.h>
#include <stdio.h>

// function prototype
size_t intlen(int x);
unsigned rightrot(unsigned x, int n);

int main(void)
{
    unsigned x;
    int n;

    printf("Enter a number: ");
    scanf("%u", &x);
    printf("How many times to rotate: ");
    scanf("%d", &n);
    printf("rightrot(%u, %d) => %u\n", x, n, rightrot(x, n));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    // what does it mean by rotating to the right by n position?
    // it says integer so the function seems to do something to the integer.
    // for example, if x equals 1024, then rightrot(1024, 1) will give 4102.
    // rightrot(1024, 2) returns 2410. I think this is what it means.
    // I think this is simply done using operations with base 10 numbers,
    // nothing to do with bit operations..
    size_t len = intlen(x);
    n = n % len;

    unsigned front = x % (int)pow(10, n);
    unsigned back = x / pow(10, n);

    return front * pow(10, len - n) + back;
}

size_t intlen(int x)
{
    size_t len;

    for (len = 0; x > 0; x /= 10) {
        len++;
    }
    return len;
}
