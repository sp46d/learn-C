// Exercise 1-20. Write a program detab that replaces tab in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?

#include <stdio.h>

#define TABSIZE 8

// Funcntion prototype
int next_tab_stop(int column, int tab_size);

int main(void)
{
    int c, num_spaces;
    int column = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == '\t')
        {
            num_spaces = next_tab_stop(column, TABSIZE) - column;
            for (int i = 0; i < num_spaces; i++)
            {
                printf(" ");
                column++;
            }
        }
        else
        {
            putchar(c);
            column++;
        }
    }
    printf("\n");
    return 0;
}

int next_tab_stop(int column, int tab_size)
{
    int c = 0;
    while ((c += tab_size) <= column)
        ;
    return c;
}
