#include "deque.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(void)
{
    int ch;
    int d;
    DEQUEinit(N);
    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            DEQUEpush_l(ch);
        } else if (islower(ch)) {
            DEQUEpush_r(ch);
        } else if (ch == '+') {
            printf("> %c\n", DEQUEpop_l());
        } else if (ch == '*') {
            printf("> %c\n", DEQUEpop_r());
        }
    }
}
