#include "poker.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./main <number of players>\n");
        exit(1);
    }
    int N = atoi(argv[1]);
    POKERinit(N);
    POKERbegin();
    return 0;
}
