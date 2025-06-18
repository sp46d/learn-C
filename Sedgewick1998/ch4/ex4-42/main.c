#include "rq.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void)
{
    char ch;
    int d;
    RQinit(N);
    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            RQpush(ch);
        } else if (ch == '*') {
            d = RQpop();
            if (d > 0) {
                if (isdigit(d)) {
                    printf("> %d\n", d - '0');
                } else {
                    printf("> %c\n", d);
                }
            }
        }
    }
    return 0;
}
