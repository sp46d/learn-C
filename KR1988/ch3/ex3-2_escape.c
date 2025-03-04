// Exercise 3-2. Write a function escape(s, t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies the
// string t to s. Use a switch. Write a function for the other direction as
// well, converting escape sequences into the real characters.

#include <stdio.h>

void escape(char s[], char t[]);

int main(void)
{
    char newline[1000];
    char* example
        = "This is my example sentence.\nthere are lots of escape sequences in "
          "this sentence.\tAnd I will see if those example sequences can be "
          "printed with my function.\vLet's see";
    printf("Original:\n%s\n", example);
    escape(example, newline);
    printf("New:\n%s\n", newline);
    return 0;
}

// escape: convert escape sequences into visible literal escape sequences as it
// copies the string s to t
void escape(char s[], char t[])
{
    int c, i, j;

    for (i = j = 0; (c = s[i]) != '\0'; i++) {
        switch (c) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\b':
            t[j++] = '\\';
            t[j++] = 'b';
            break;
        case '\a':
            t[j++] = '\\';
            t[j++] = 'a';
            break;
        case '\f':
            t[j++] = '\\';
            t[j++] = 'f';
            break;
        case '\r':
            t[j++] = '\\';
            t[j++] = 'r';
            break;
        case '\v':
            t[j++] = '\\';
            t[j++] = 'v';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
}
