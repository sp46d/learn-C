// Exercise 4-1. Write the function strindex(s,t) which returns the position of
// the rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int i;

    while (my_getline(line, MAXLINE) > 0) {
        if ((i = strindex(line, pattern)) >= 0) {
            printf("<- '%s' appeared at %d\n", pattern, i);
            found++;
        }
    }
    return found;
}

int my_getline(char line[], int max)
{
    int ch;
    int i = 0;

    // EOF is the key that halts the whole program currently running.
    // --max instead of max-- because of '\0' at the end
    while (--max > 0 && (ch = getchar()) != EOF && ch != '\n')
        line[i++] = ch;
    if (ch == '\n')
        line[i++] = ch;
    line[i] = '\0';
    // returns the length of the line
    return i;
}

// strindex: returns the index of the rightmost occurrence of t in s
int strindex(char s[], char t[])
{
    int i, j, k;
    int rightmost_index = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            rightmost_index = i;
    }
    return rightmost_index >= 0 ? rightmost_index : -1;
}
