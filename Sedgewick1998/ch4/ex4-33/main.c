#include "queue.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int d;
    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            QUEUEput(ch);
        } else if (ch == '*') {
            printf("> ");
            if ((d = QUEUEget()) >= 0)
                printf("%c\n", d);
        }
    }
}
