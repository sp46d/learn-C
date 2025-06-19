#include "item.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./main \"<STRING>\"\n");
        exit(1);
    }
    STACKinit();
    char* s = argv[1];
    char ch;
    int d;
    for (; (ch = *s) != '\0'; s++) {
        d = 0;
        if (isalnum(ch)) {
            STACKpush(ch);
        } else if (ch == '*') {
            d = STACKpop();
        }
        printf("%c   %c   %s\n", ch, d > 0 ? d : ' ', STACKdump());
    }
    return 0;
}
