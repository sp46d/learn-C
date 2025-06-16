#include "queue.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(void)
{
    char ch;
    int c;
    QUEUEinit(N);
    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            QUEUEput(ch);
        } else if (ch == '>') {
            printf(">> ");
            while (!QUEUEempty()) {
                printf("%c", QUEUEget());
            }
            printf("\n");
        }
    }
}
