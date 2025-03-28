#include <ctype.h>
#include <stdio.h>
#define MAX_LEN 100
int read_line(char str[], int n);
int read_line_a(char str[], int n);
int read_line_b(char str[], int n);

int main(void)
{
    char str[MAX_LEN + 1];
    printf("Enter: ");
    int num_ch = read_line_b(str, MAX_LEN);
    printf("Received: %s\nNumber of characters: %d\n", str, num_ch);
    return 0;
}

int read_line(char str[], int n)
{
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';
    return count;
}

// Modify the read_line function in each of the following ways:
// (a) Have it skip white space before beginning to store input characters
int read_line_a(char str[], int n)
{
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF && isspace(ch))
        ;
    str[count++] = ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';

    return count;
}
// (b) Have it stop reading at the first white-space character
int read_line_b(char str[], int n)
{
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n' && !isspace(ch))
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';
    return count;
}
