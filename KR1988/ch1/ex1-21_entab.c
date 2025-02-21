// Exercise 1-21. Write a program entab that replaces strings of blanks
// by the minimum number of tabs and blanks to achieve the same sapcing.
// Use the same tab stops as for detab. When either a tab or a single blank
// would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000
#define TABSIZE 8
#define IN 1
#define OUT 0

// function prototype
bool is_tab_stop(int column, int tab_size);

int main(void)
{
    int c;
    int column = 0;
    int num_blanks = 0;
    int state = OUT;
    char line[MAXLINE];

    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        if (c == ' ' && state == OUT)
        {
            state = IN;
            num_blanks++;
        }
        else if (c == ' ' && state == IN && !is_tab_stop(i, TABSIZE))
            num_blanks++;
        else if (c == ' ' && state == IN && is_tab_stop(i, TABSIZE))
        {
            line[column] = '\t';
            num_blanks = 1;
            column++;
        }
        else if (c != ' ' && state == IN && !is_tab_stop(i, TABSIZE))
        {
            state = OUT;
            for (int j = 0; j < num_blanks; j++)
            {
                line[column] = ' ';
                column++;
            }
            num_blanks = 0;
            line[column] = c;

            column++;
        }
        else if (c != ' ' && state == IN && is_tab_stop(i, TABSIZE))
        {
            state = OUT;
            line[column] = '\t';
            num_blanks = 0;
            column++;
            line[column] = c;
            column++;
        }
        else if (c != ' ' && state == OUT)
        {
            line[column] = c;
            column++;
        }
    }
    line[column] = '\0';

    printf("%s\n", line);
    return 0;
}

bool is_tab_stop(int column, int tab_size)
{
    return (column % tab_size == 0) ? true : false;
}
