// Exercise 2-5. Write the function any(s1, s2), which returns the first location in a string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the location.)

#include <stdio.h>

// function prototype
int any(char s1[], char s2[]);

int main(void)
{
    char *s1 = "Hello! my name is will! I am 39 years old.";
    char s2[100];
    int l;

    printf("Entered sentence: %s\n", s1);
    printf("Characters: ");
    scanf("%s", s2);

    if ((l = any(s1, s2)) == -1)
    {
        printf("None of the characters in '%s' found in the sentence.\n", s2);
        return 1;
    }
    printf("One of the characthers in '%s' found at %d\n", s2, l + 1);
    return 0;
}

int any(char s1[], char s2[])
{
    int i, c;
    for (i = 0; (c = s1[i]) != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (c == s2[j])
                return i;
        }
    }
    return -1;
}
