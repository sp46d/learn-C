#include "deque.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./main \"<STRING>\"\n");
        exit(1);
    }
    char* s = argv[1];
    char ch;
    int d;
    for (ch = *s; ch != '\0'; ch = *++s) {
        d = 0;
        if (isupper(ch)) {
            DEQUEpush_l(ch);
        } else if (islower(ch)) {
            DEQUEpush_r(ch);
        } else if (ch == '+') {
            d = DEQUEpop_l();
        } else if (ch == '*') {
            d = DEQUEpop_r();
        }
        printf("%c\t%c\t", ch, d > 0 ? d : ' ');
        DEQUEdump();
    }
    return 0;
}
