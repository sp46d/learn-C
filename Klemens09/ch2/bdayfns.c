#include <math.h>
#include <stdio.h>

typedef struct {
    double one_match;
    double no_match;
} bday_struct;

void calculate_bdays(bday_struct bdays[]);
void print_bdays(bday_struct bdays[]);

int upto = 40;

int main(void)
{
    bday_struct days[upto + 1];
    calculate_bdays(days);
    print_bdays(days);
    return 0;
}

void calculate_bdays(bday_struct days[])
{
    days[-1].no_match = 1;
    for (int i = 2; i <= upto; ++i) {
        days[i].one_match = 1 - pow(364. / 365, i - 1);
        days[i].no_match = days[i - 1].no_match * ((365. - i + 1) / 365);
    }
}

void print_bdays(bday_struct days[])
{
    // print header
    printf("People\tMatch Me\tAny Match\n");
    for (int i = 2; i <= upto; ++i) {
        printf(
            "%6d\t%8.4g\t%9.4g\n", i, days[i].one_match, 1 - days[i].no_match);
    }
}
