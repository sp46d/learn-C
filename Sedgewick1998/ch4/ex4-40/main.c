#include "queue.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    int d;
    QUEUEinit();
    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            QUEUEput(ch);
        } else if (ch == '*') {
            d = QUEUEget();
            if (d > 0) {
                printf("> %c\n", d);
            }
        }
    }
}