// Write a function named "censor" that modifies a string by replacing every
// occurrence of foo by xxx. For example, the string "food fool" would become
// "xxxd xxxl". Make the function as short as possible without sacrificing
// clarity.
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 100

void censor(char new[], const char original[], const char target_word[]);

int main(void)
{
    char str[BUF_SIZE];
    char censored[BUF_SIZE];
    printf("Enter: ");
    fgets(str, BUF_SIZE, stdin);

    censor(censored, str, "foo");
    printf("Censored: %s\n", censored);
    return 0;
}

void censor(char* new, const char* original, const char* target_word)
{
    const char *p1, *p2;

    while (*original) {
        if (*original == *target_word) {
            p1 = original;
            p2 = target_word;
            while ((*++p1 == *++p2) && (*p2 != '\0'))
                ;
            if (*p2 == '\0') {
                while (p1 - original) {
                    *new ++= 'x';
                    original++;
                }
                continue;
            }
        }
        *new ++= *original++;
    }
    *--new = '\0';
}
