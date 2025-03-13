// Exercise 3-6. Write a version of itoa that accepts three arguments instead of
// two. The third argument is a minimum field width; the converted number must
// be padded with blanks on the left if necessary to make it wide enough.

#include <limits.h>
#include <stdio.h>

#define EQ_MIN 1
#define NOT_EQ_MIN 0

void itoa(int number, char str[], int width);
void reverse(char str[], size_t n);

int main(void)
{
    int n, test;
    char str[100];

    printf("Enter a number (%d, %d): ", INT_MIN, INT_MAX);
    scanf("%d", &n);

    itoa(n, str, 8);
    printf("Received: %s\n", str);
    return 0;
}

void itoa(int number, char str[], int width)
{
    int i = 0;
    int state = NOT_EQ_MIN;
    int d, sign;

    if (number < 0) {
        sign = number;
        if (number == INT_MIN) {
            state = EQ_MIN;
            number = INT_MAX;
        } else {
            number *= -1;
        }
    }

    do {
        d = number % 10;
        if (state == EQ_MIN) {
            d++;
            state = NOT_EQ_MIN;
        }
        str[i++] = '0' + d;
        width--;
    } while (number /= 10);

    if (sign < 0) {
        str[i++] = '-';
        width--;
    }

    if (width) {
        while (width > 0) {
            str[i++] = ' ';
            width--;
        }
    }

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
