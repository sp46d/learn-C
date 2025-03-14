#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double my_atof(char s[]);

int main(void)
{
    char s[100];
    printf("Enter: ");
    scanf("%s", s);

    printf("Received: %g\n", my_atof(s));
    return EXIT_SUCCESS;
}

// my_atof: converts a string s to float number. Also works for a scientific
// notation of numbers, e.g. 123.45e-6 -> 0.00012345
double my_atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-')
            power *= pow(10.0, s[++i] - '0');
        else if (s[i] == '+')
            power *= pow(10.0, -(s[++i] - '0'));
    }

    return (val * sign) / power;
}
