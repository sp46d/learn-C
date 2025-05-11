#include <stdio.h>

int strend(char* s, char* t);

int main(void)
{
    char* s = "hello world!";
    char* t = "ld!";

    printf("strend(\"hello world!\", \"ld!\") = %d\n", strend(s, t));
    return 0;
}

int strend(char* s, char* t)
{
    char* pt = t;
    while (*s != '\0') {
        if (*s == *pt)
            pt++;
        else
            pt = t;
        s++;
    }
    if (*pt == '\0')
        return 1;
    return 0;
}