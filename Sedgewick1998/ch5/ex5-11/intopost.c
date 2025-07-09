// Exercise 5.11
// Write a recursive program that converts infix expressions to postfix.

#include <stdio.h>
#include <stdlib.h>

void parse(char* a, int* i)
{
    // void parse(char *, int): A parser that converts an infix expression, a,
    // into a postfix expression.

    // remove whitespaces and opening parenthesis
    while (a[*i] == ' ' || a[*i] == '(') {
        (*i)++;
    }

    if (a[*i] >= '0' && a[*i] <= '9') {
        while (a[*i] >= '0' && a[*i] <= '9') {
            printf("%c", a[*i]);
            (*i)++;
        }
        printf(" ");
    } else if (a[*i] == '+') {
        (*i)++;
        parse(a, i);
        printf("+ ");
    } else if (a[*i] == '-') {
        (*i)++;
        parse(a, i);
        printf("- ");
    } else if (a[*i] == '*') {
        (*i)++;
        parse(a, i);
        printf("* ");
    } else if (a[*i] == '/') {
        (*i)++;
        parse(a, i);
        printf("/ ");
    } else if (a[*i] == ')') {
        (*i)++;
        return;
    } else if (a[*i] == '\0') {
        return;
    }
    parse(a, i);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./intopost \"<EXPRESSION>\"\n");
        exit(1);
    }
    int i = 0;
    char* a = argv[1];
    parse(a, &i);
    printf("\n");
}