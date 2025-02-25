// Exercise 2-4. Write an alternative version of squeeze(s1, s2) that deletes
// each character in s1 that matches any character in string s2.
#include <stdio.h>

void my_squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[100];
    char s2[1000];
    int c;
    int i = 0;

    printf("Enter a set of characters to remove: ");
    scanf("%s", s1);
    printf("Enter text: ");
    while ((c = getchar()) != EOF)
    {
        s2[i++] = c;
    }
    s2[i] = '\0';

    printf("\n---------- Received ----------\n");
    printf("Characters to remove: %s\n", s1);
    printf("Original text: %s\n", s2);

    my_squeeze(s1, s2);
    printf("\n----------- Result -----------\n");
    printf("%s\n", s2);

    return 0;
}

void my_squeeze(char s1[], char s2[])
{
    int c1, c2, to_be_removed;
    int k = 0;
    for (int i = 0; (c1 = s2[i]) != '\0'; i++)
    {
        to_be_removed = 0;
        for (int j = 0; (c2 = s1[j]) != '\0'; j++)
        {
            if (c1 == c2)
            {
                to_be_removed = 1;
                break;
            }
        }
        if (to_be_removed)
            continue;
        else
            s2[k++] = c1;
    }
    s2[k] = '\0';
}