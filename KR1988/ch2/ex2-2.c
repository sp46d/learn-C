// Exercise 2-2. Write a loop equivalent to the for loop above without
// using && or ||.

// a program that returns the longest line
#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

// print the longest input line
int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("- Longest line:\n%s\n", longest);
    return 0;
}

// getline: read a line into s, return length
int my_getline(char s[], int lim)
{
    int c, i;

    // for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        else
            s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}