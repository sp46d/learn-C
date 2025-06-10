#include "two_stacks.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    STACKSinit(100, 100);
    for (int i = 0; i < 10; i++) {
        STACKpush(0, i);
        STACKpush(1, i * 10);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", STACKpop(0) + STACKpop(1));
    }
    printf("Now the first stack %s empty\n", STACKempty(0) ? "is" : "is not");
    printf("Now the second stack %s empty\n", STACKempty(1) ? "is" : "is not");
    return 0;
}