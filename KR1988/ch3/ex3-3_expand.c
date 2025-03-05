// Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
// notations like a-z in the string s1 into the equivalent complete list
// abc...xyz in s2. Allow for letters of either case and digits, and be prepared
// to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
// trailing - is taken literally.

#include <ctype.h>
#include <stdio.h>

void expand(char s1[], char s2[]);

int main(void)
{
    char newline[1000];

    char* line = "This is my example sentence. Here is 0-9, a-z, A-Z, and "
                 "a-z0-9. How about a-b-c? Maybe -a-b-c-d-e-?";
    printf("Original: %s\n", line);

    expand(line, newline);
    printf("Line expanded:\n");
    printf("%s\n", newline);

    return 0;
}

// Now it works. But can I replace the part that repeats itself with a function?
// Maybe later.
void expand(char s1[], char s2[])
{
    int j = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            if (s1[i + 1] == '-' && s1[i + 2] >= 'a' && s1[i + 2] <= 'z'
                && s1[i] < s1[i + 2]) {
                int start = s1[i];
                int end = s1[i + 2];
                for (int k = 0; k <= end - start; k++)
                    s2[j++] = start + k;
                i += 2;
            } else
                s2[j++] = s1[i];
        } else if (s1[i] >= 'A' && s1[i] <= 'Z') {
            if (s1[i + 1] == '-' && s1[i + 2] >= 'A' && s1[i + 2] <= 'Z'
                && s1[i] < s1[i + 2]) {
                int start = s1[i];
                int end = s1[i + 2];
                for (int k = 0; k <= end - start; k++)
                    s2[j++] = start + k;
                i += 2;
            } else
                s2[j++] = s1[i];
        } else if (s1[i] >= '0' && s1[i] <= '9') {
            if (s1[i + 1] == '-' && s1[i + 2] >= '0' && s1[i + 2] <= '9'
                && s1[i] < s1[i + 2]) {
                int start = s1[i];
                int end = s1[i + 2];
                for (int k = 0; k <= end - start; k++)
                    s2[j++] = start + k;
                i += 2;
            }
        } else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}
