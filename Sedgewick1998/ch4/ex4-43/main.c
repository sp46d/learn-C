#include "rq.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int d;
    RQinit();
    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            RQpush(ch);
        } else if (ch == '*') {
            printf("> ");
            while (!RQempty()) {
                d = RQpop();
                if (isdigit(d)) {
                    printf("%d ", d - '0');
                } else {
                    printf("%c ", d);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
