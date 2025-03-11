// This program provides a function itos(), which converts an integer into a
// string. This version of the function takes care of the issue, where the least
// (or largest) negative number causes an overflowing integer.

#include <stdio.h>

// function prototypes
void reverse(char str[], size_t n);
void itos(int number, char str[]);

int main(void)
{
    int n, test;
    char str[100];

    test = -123;
    printf("Test number: %d\n", test);
    test >>= 1;
    printf("1-bit right-shifted: %d\n", test);
    return 0;

    /* printf("Enter a number: "); */
    /* scanf("%d", &n); */

    /* itos(n, str); */
    /* printf("Received: %s\n", str); */
    /* return 0; */
}

void itos(int number, char str[])
{
    int i = 0;
    int sign;

    if (number < 0) {
        sign = number;
        number *= -1; // this line is problematic.
    }

    str[0] = '\0';
    while (number) {
        int d = number % 10;
        str[++i] = '0' + d;
        number /= 10;
    }

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
