// Exercise 2-3. Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f, and A
// through F.

#include <stdio.h>

// function prototype
int htoi(char s[]);

int main(void)
{
    char hex_string[1000];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_string);

    int d = htoi(hex_string);
    if (d == -1)
    {
        printf("Not a valid hexadecimal number.\n");
        return 1;
    }
    printf("Converted into decimal: %d\n", d);
    printf("Double-check: %x\n", d);
    return 0;
}

int htoi(char s[])
{
    int d;
    int n = 0;

    for (int i = 0; (d = s[i]) != '\0'; i++)
    {
        if (i == 0 && d == '0')
            continue;
        else if (i == 1 && (d == 'x' || d == 'X'))
            continue;
        else if (d >= '0' && d <= '9')
            n = n * 16 + (d - '0');
        else if (d >= 'a' && d <= 'f')
            n = n * 16 + (d - 'a' + 10);
        else if (d >= 'A' && d <= 'F')
            n = n * 16 + (d - 'A' + 10);
        else
            return -1;
    }
    return n;
}