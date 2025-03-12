// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to
// -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs.

// A: That's because the function itoa first converts the sign of the number to
// positive and do the rest of the work with this number. In a two's complement
// number representation, the absolute value of the largest positive number is
// exactly one less than the absolute value of the largest negative number.
// Thus, if we convert the largest negative number to positive, we will be
// having an overflow, which causes a bug. The below is my answer to this issue.

// This program provides a function itos(), which converts an integer into a
// string. This version of the function takes care of the issue, where the least
// (or largest) negative number causes an overflowing integer.

#include <limits.h>
#include <stdio.h>

#define EQ_MAX 1
#define LESS_MAX 0

// function prototypes
void reverse(char str[], size_t n);
void itoa(int number, char str[]);

int main(void)
{
    int n, test;
    char str[100];

    printf("Enter a number (%d, %d): ", INT_MIN, INT_MAX);
    scanf("%d", &n);

    itoa(n, str);
    printf("Received: %s\n", str);
    return 0;
}

void itoa(int number, char str[])
{
    int i = 0;
    int state = LESS_MAX;
    int sign;

    // If the given number is negative, it'll be converted into positive. Why
    // not negative numbers? It's because arithmetic operations on
    // negative numbers can produce different results depending on the
    // machine. So it's necessary to convert negative numbers into positive
    // for reliable results regardless of machines. But, just multiplying the
    // number by -1 will not suffice due to the issue mentioned above. So, I
    // chose the following way.

    if (number < 0) {
        sign = number;
        if (number == INT_MIN) {
            state = EQ_MAX;
            number = INT_MAX;
        } else {
            number *= -1;
        }
    }

    // do-while loop is necessary, because it should work even when the given
    // number is 0
    do {
        int d = number % 10;
        if (state == EQ_MAX) {
            // Since the absolute value of INT_MIN is greater than that of
            // INT_MAX by one, we compensate it just once.
            d++;
            state = LESS_MAX;
        }
        str[i++] = '0' + d;
    } while (number /= 10);

    if (sign < 0)
        str[i++] = '-';

    str[i] = '\0';
    reverse(str, i);
}

void reverse(char str[], size_t n)
{
    int i, j, tmp;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
