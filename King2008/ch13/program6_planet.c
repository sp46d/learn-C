#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NUM_PLANETS 9

char* planets[] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
    "Uranus", "Neptune", "Pluto" };

int main(int argc, char* argv[])
{
    // Original version:

    // int i;
    // char** p;
    // for (p = &argv[1]; *p != NULL; p++) {
    //     for (i = 0; i < NUM_PLANETS; i++) {
    //         if (strcmp(*p, planets[i]) == 0) {
    //             printf("%s is a planet.\n", *p);
    //             break;
    //         }
    //     }
    //     if (i == NUM_PLANETS)
    //         printf("%s is not a planet.\n", *p);
    // }

    // return 0;

    // Improved version: now the function is case-insensitive
    int i, j;
    char **p, *q;
    for (p = &argv[1]; *p != NULL; p++) {

        for (i = 0; i < NUM_PLANETS; i++) {
            for (j = 0, q = planets[i]; *q; j++, q++)
                if (tolower(*(*p + j)) != tolower(*q))
                    break;
            if (*q == '\0' && *(*p + j) == '\0') {
                printf("%s is planet.\n", *p);
                break;
            }
        }
        if (i == NUM_PLANETS)
            printf("%s is not a planet.\n", *p);
    }

    return 0;
}
