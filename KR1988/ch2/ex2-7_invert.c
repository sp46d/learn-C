// Exercise 2-7. Write a function invert(x, p, n) that returns x with the n bits
// that begin at position p inverted (i.e. 1 changed into 0 and vice versa),
// leaving the others unchanged.

#include <stddef.h>
#include <stdio.h>

// function prototype
unsigned invert(unsigned x, int p, int n);
size_t bitlength(unsigned x);

int main(void) {
    unsigned x;

    printf("Enter a number: ");
    scanf("%u", &x);
    // x = 11000 <- 24
    // invert(24, 1, 3) => 10110 <- 16 + 4 + 2 = 22
    // x = 1111 <- 15
    // invert(15, 1, 3) => 1000 <- 8
    printf("invert(%u, 1, 3) => %u\n", x, invert(x, 1, 3));

    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    int target_loc = bitlength(x) - p - n;

    return x ^ (~(~0 << n) << target_loc);
}

size_t bitlength(unsigned x) {
    size_t length = 0;

    while (x > 0) {
        x >>= 1;
        length++;
    }
    return length;
}
