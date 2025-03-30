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
    char **p, *p1, *p2;
    for (p = &argv[1]; *p != NULL; p++) {
        for (i = 0; i < NUM_PLANETS; i++) {
            for (p1 = *p, p2 = planets[i]; *p2; ++p1, ++p2)
                if (tolower(*p1) != tolower(*p2))
                    break;
            if (!*p1 && !*p2) {
                printf("%s is planet.\n", *p);
                break;
            }
        }
        if (i == NUM_PLANETS)
            printf("%s is not a planet.\n", *p);
    }

    return 0;
}
