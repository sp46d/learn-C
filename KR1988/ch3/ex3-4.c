// This program provides a function itos(), which converts an integer into a
// string. This version of the function takes care of the issue, where the least
// (or largest) negative number causes an overflowing integer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itos(int number);

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    char* d = itos(n);

    printf("Received: %s\n", d);
    printf("The length of the number: %lu\n", strlen(d));
    return 0;
}

char* itos(int number)
{
    char* result = malloc(100 * sizeof(char));
    int i = 0;
    result[0] = '\0';
    while (number) {
        int d = number % 10;
        i++;
        result[i] = '0' + d;
        number /= 10;
    }

    int j, tmp;
    for (j = 0; j < i; j++, i--) {
        tmp = result[j];
        result[j] = result[i];
        result[i] = tmp;
    }
    return result;
}
