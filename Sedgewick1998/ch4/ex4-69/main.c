#include "complex.h"
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

    Stack stack = STACKinit();
    char* s = argv[1];
    int digits[2];
    for (int i = 0; i < 2; i++) {
        digits[i] = 0;
    }
    // Remove leading white spaces
    for (; isspace(*s); s++)
        ;
    char ch;
    int sign = 1;
    int i = 0;
    for (; (ch = *s) != '\0'; s++) {
        if (isdigit(ch)) {
            while (isdigit(ch)) {
                digits[i] = 10 * digits[i] + sign * (ch - '0');
                s++;
                ch = *s;
            }
            i++;
            sign = 1;
        }
        if (ch == '-') {
            sign = -1;
        } else if (ch == ' ') {
            if (i != 0) {
                STACKpush(stack, COMPLEXinit(digits[0], digits[1]));
                for (int j = 0; j < 2; j++) {
                    digits[j] = 0;
                }
                i = 0;
            }
        } else if (ch == '+' && i == 0) {
            STACKpush(stack, COMPLEXadd(STACKpop(stack), STACKpop(stack)));
        } else if (ch == '*') {
            STACKpush(stack, COMPLEXmult(STACKpop(stack), STACKpop(stack)));
        } else if (ch == '.') {
            printf("> ");
            COMPLEXprint(STACKpop(stack));
        }
    }
    printf("\n");
    STACKdestroy(stack);
}
