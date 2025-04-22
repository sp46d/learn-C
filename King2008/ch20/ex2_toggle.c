#include <stdio.h>

int main(void)
{
    unsigned int a;
    int n;
    printf("Enter a number: ");
    scanf("%u", &a);
    printf("Which bit to toggle: ");
    scanf("%d", &n);

    a = (a & (1 << n)) ? a & ~(1 << n) : a | (1 << n);
    printf("After toggled: %u\n", a);
    return 0;
}
