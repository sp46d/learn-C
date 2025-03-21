#include <limits.h>
#include <stdio.h>

void itoa(int number, char s[]);

int main(void)
{
    char s[100];
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    itoa(n, s);
    printf("String: %s\n", s);
    return 0;
}

void itoa(int number, char s[])
{
    static int i = 0;

    if (number < 0) {
        number *= -1;
        s[i++] = '-';
    }

    if (number / 10)
        itoa(number / 10, s);

    s[i++] = number % 10 + '0';
    s[i] = '\0';
}