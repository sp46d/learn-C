#include <stddef.h>
#include <stdio.h>
#define MAX_CHAR 101

void reverse(char input[], size_t len);
void reverse_pointer(char input[], size_t len);

int main(void)
{
    char ch;
    char received[MAX_CHAR];
    printf("Enter a message: ");
    size_t count = 0;
    while ((ch = getchar()) != EOF && ch != '\n' && count < MAX_CHAR - 1)
        received[count++] = ch;
    reverse_pointer(received, count);
    received[count] = '\0';
    printf("Reversal is: %s\n", received);
    return 0;
}

void reverse(char input[], size_t len)
{
    char tmp;
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
    }
}

void reverse_pointer(char* input, size_t len)
{
    char tmp, *p, *q;
    for (p = input, q = input + len - 1; p < q; ++p, --q) {
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
}
