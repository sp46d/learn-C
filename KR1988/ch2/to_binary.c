#include <ctype.h>
#include <math.h>
#include <stdio.h>

unsigned long to_binary(int n);
int stoi(char s[]);

int main(void) {
    char n[1000];

    printf("Enter a number: ");
    scanf("%s", n);

    int d = stoi(n);
    if (d == -1) {
        printf("Valid format of number: octal starts with 0 and hexadecimal "
               "starts with 0x.\n");
        return 1;
    }

    printf("Binary representation of %5s: %lu\n", n, to_binary(d));
    // printf("Binary representation of   077: %20lu\n\n",
    // to_binary(stoi("0177700")));

    // printf("Thus, %s & 0177700 => %d\n", n, d & 0177700);
    return 0;
}

unsigned long to_binary(int n) {
    unsigned long result = 0;

    for (int i = 0; n > 0; n /= 2)
        result += (n % 2) * pow(10, i++);

    return result;
}

int stoi(char s[]) {
    int c;
    int base = 10;
    int d = 0;

    for (int i = 0; (c = s[i]) != '\0'; i++) {
        c = tolower(c);
        if (i == 0 && c == '0')
            base = 8;
        else if (i == 1 && c == 'x' && s[0] == '0')
            base = 16;
        else if (base == 16) {
            if (c >= '0' && c <= '9')
                d = d * base + (c - '0');
            else if (c >= 'a' && c <= 'f')
                d = d * base + (c - 'a' + 10);
            else {
                printf(
                    "Received: %s; Not a valid format of hexadecimal number.\n",
                    s);
                return -1;
            }
        } else if (base == 8) {
            if (c >= '0' && c <= '7')
                d = d * base + (c - '0');
            else {
                printf("Received: %s; Not a valid format of octal number.\n",
                       s);
                return -1;
            }
        } else {
            if (c >= '0' && c <= '9')
                d = d * base + (c - '0');
            else {
                printf("Received: %s; Not a valid format of number.\n", s);
                return -1;
            }
        }
    }
    return d;
}
