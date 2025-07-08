// Can I do this without using a pushdown stack? Only with recursive calls?
// I think for this particular implementation, I need to use stack. Recursive
// calls are used to just replace for or while loops, but not the stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* a;
int i;

int eval(void)
{
    int x = 0;
    int digit = 1;
    // remove whitespaces
    while (a[i] == ' ') {
        i--;
    }
    if (i < 0) {
        return -1;
    }
    if (a[i] == '+') {
        i--;
        return eval() + eval();
    }
    if (a[i] == '*') {
        i--;
        return eval() * eval();
    }
    while (a[i] >= '0' && a[i] <= '9') {
        x += digit * (a[i] - '0');
        i--;
        digit *= 10;
    }
    return x;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./postfix \"<EXPRESSION>\"\n");
        exit(1);
    }
    a = argv[1];
    i = strlen(a) - 1;
    printf("> %d\n", eval());
    return 0;
}