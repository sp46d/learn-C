// Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stddef.h>
#include <stdio.h>

// function prototype
unsigned setbits(unsigned x, int p, int n, unsigned y);
size_t bitlength(unsigned x);

int main(void) {
    unsigned x, y;

    // x = 1101011 <- 64 + 32 + 8 + 3 = 107
    // y = 1000100 <- 64 + 4 = 68
    // setbits(x, 2, 3, y) => 1110011 <- 64 + 32 + 16 + 3 = 115
    // setbits(x, 1, 2, y) => 1001011 <- 64 + 8 + 3 = 75

    // x = 101011 <- 32 + 8 + 3 = 43
    // y = 11010 <- 16 + 8 + 2 = 26
    // setbits(x, 2, 3, y) => 100101 <- 37
    // setbits(x, 1, 2, y) => 110011 <- 32 + 16 + 3 = 51

    printf("Enter a number (x, y): ");
    scanf("%u, %u", &x, &y);
    printf("setbits(%u, 2, 3, %u) => %u\n", x, y, setbits(x, 2, 3, y));
    printf("setbits(%u, 1, 2, %u) => %u\n", x, y, setbits(x, 1, 2, y));

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // My plan for this function:
    // 1. set the target bits of x to 0
    //    -> first get the target bits
    //    -> pad 0 to the right until the target bit reaches its location
    //    -> use ^ to get the desired output
    // 2. get the right-most n bits of y
    // 3. align the n bits of y with the target bits of x by padding 0 to the
    // right
    // 4. add them up

    // takes the right-most n bits of y
    size_t xbitlen = bitlength(x);
    /* size_t ybitlen = bitlength(y); */
    int loc = xbitlen - p - n;
    unsigned ytargetbit = y & ~(~0 << n);
    unsigned xtargetbit = (x >> loc) & ~(~0 << n);

    return ((xtargetbit << loc) ^ x) + (ytargetbit << loc);
}

// returns the length of bits of x
size_t bitlength(unsigned x) {
    size_t length = 0;

    while (x > 0) {
        x >>= 1;
        length++;
    }
    return length;
}
