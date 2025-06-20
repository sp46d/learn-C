#include "queue.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./main \"<STRING>\"\n");
        exit(1);
    }
    QUEUEinit(N);
    char* s = argv[1];
    char ch;
    Item item;
    for (; (ch = *s) != '\0'; s++) {
        item = 0;
        if (isalnum(ch)) {
            QUEUEput(ch);
        } else if (ch == '*') {
            item = QUEUEget();
        }
        printf("%c  %c  ", ch, item > 0 ? item : ' ');
        QUEUEdump();
        printf("\n");
    }
    return 0;
}
