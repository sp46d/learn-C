// Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
// a base b character representation in the string s. In particular,
// itob(n,s,16) formats s as a hexadecimal integer in s.

#include <stdio.h>

void itob(int n, char s[], unsigned b);
void reverse(char s[], size_t len);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    unsigned b;
    printf("To what base: ");
    scanf("%d", &b);

    char s[1000];
    itob(n, s, b);
    printf("Result: %s\n", s);
    return 0;
}

void itob(int n, char s[], unsigned b)
{
    int i = 0;
    s[i] = '\0';

    do {
        if (b == 16)
            s[++i] = "0123456789ABCDEF"[n % b];
        else
            s[++i] = '0' + (n % b);
    } while (n /= b);

    if (b == 16) {
        s[++i] = 'x';
        s[++i] = '0';
    } else if (b == 8) {
        s[++i] = '0';
    }

    reverse(s, i);
}

void reverse(char s[], size_t len)
{
    int i, j, tmp;
    for (i = 0, j = len; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
