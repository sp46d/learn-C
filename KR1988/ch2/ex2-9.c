// Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
// rightmost 1-bit in x. Explain why. Use this observation to write a faster
// version of bit count.

// My answer: In a two's complement number system, there are only two numbers
// that can exist in a number, 0 and 1. When subtracting 1 from any number, its
// least significant bit becomes 0 if it's 1; or it borrows from the next least
// significant bit and becomes 1 if it's 0. This borrow keeps on going until it
// finally reaches the first non-zero bit. Then this non-zero bit becomes 0, and
// all the bits less significant than the first non-zero bit become 1. The bits
// more significant than the first non-zero bit will remain unaffected. In other
// words, the bits in (x-1) will become opposite at the position of the first
// non-zero bit and all the way through to the least significant bit. Thus,
// applying the bit operation & to (x-1) and x will effectively sets all the
// bits on the right side of the first non-zero bit to 0, which is equivalent to
// deleting the right most 1-bit.

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned x;
    printf("Enter a number: ");
    scanf("%u", &x);

    printf("Number of 1-bits in %u is: %d\n", x, bitcount(x));

    return 0;
}

int bitcount(unsigned x)
{
    int n;
    for (n = 0; x > 0; x &= (x - 1)) {
        n++;
    }
    return n;
}
