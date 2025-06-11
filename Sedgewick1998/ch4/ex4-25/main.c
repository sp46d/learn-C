#include "two_stacks.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define maxN 100

int main(void)
{
    STACKSinit(maxN, maxN);
    char ch;
    char op;
    int d = -1;
    while ((ch = getchar()) != EOF) {
        if (isdigit(ch)) {
            if (d == -1) {
                d = 0;
            }
            d = 10 * d + ch - '0';
        } else {
            if (d != -1) {
                STACKpush(0, d);
                d = -1;
            }
            if (ch == '+' || ch == '*') {
                STACKpush(1, ch);
            } else if (ch == ')') {
                op = STACKpop(1);
                if (op == '+') {
                    STACKpush(0, STACKpop(0) + STACKpop(0));
                } else if (op == '*') {
                    STACKpush(0, STACKpop(0) * STACKpop(0));
                }
            } else if (ch == '\n') {
                printf("> %d\n", STACKpop(0));
            }
        }
    }
    return 0;
}