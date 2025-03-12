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

#include <stdio.h>

// function prototypes
void reverse(char str[], size_t n);
void itoa(int number, char str[]);

int main(void)
{
    int n, test;
    char str[100];

    printf("Enter a number: ");
    scanf("%d", &n);

    itoa(n, str);
    printf("Received: %s\n", str);
    return 0;
}

void itoa(int number, char str[])
{
    int i = 0;
    int sign;

    if (number < 0) {
        sign = number;
        // why not negative numbers? It's because arithmetic operations on
        // negative numbers can produce different results depending on the
        // machine. So it's necessary to convert negative numbers into positive
        // before the computation for reliable results regardless of machines.
        // But, this way of conversion can cause an overflow in an edge case,
        // where the given number is the largest negative number. Thus, a
        // different way should be sought after.
        number *= -1;
        // what if it is given -1234 and I add this number to 5000, then the
        // result will be 3766. How can I get 1234 out of this 3766? First
        // multiply 3766 by -1 to make it negative and add 5000 and -3766
        // together, which results in exactly what I am looking for.
    }

    str[0] = '\0';
    // do-while loop is necessary, because it should work even when the given
    // number is 0
    do {
        int d = number % 10;
        str[++i] = '0' + d;
    } while (number /= 10);

    if (sign < 0)
        str[++i] = '-';

    reverse(str, i);
}

void reverse(char str[], size_t n)
{
    int i, j, tmp;
    for (i = 0, j = n; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
