// Exercise 5.12
// Write a recursive program that converts postfix expressions to infix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char* a, int* i)
{
    // I think it should start parsing it backwards from the end

    int x = 0;
    int digit = 1;
    char op;
    // remove whitespaces
    while (a[*i] == ' ') {
        (*i)--;
    }
    if ((op = a[*i]) == '+' || op == '*') {
        (*i)--;
        printf("(");
        parse(a, i);
        printf(" %c ", op);
        (*i)--;
        parse(a, i);
        printf(")");
    } else if (a[*i] >= '0' && a[*i] <= '9') {
        while (a[*i] >= '0' && a[*i] <= '9') {
            x += (a[*i] - '0') * digit;
            (*i)--;
            digit *= 10;
        }
        printf("%d", x);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./posttoin \"<EXPRESSION>\"\n");
        exit(1);
    }
    char* a = argv[1];
    int i = strlen(a) - 1;
    parse(a, &i);
    printf("\n");
}