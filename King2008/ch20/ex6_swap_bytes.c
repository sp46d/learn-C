#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(void)
{
    unsigned short i, swapped_i;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);
    swapped_i = swap_bytes(i);
    printf("Number with bytes swapped: %hx\n", swapped_i);
    return 0;
}

unsigned short swap_bytes(unsigned short i)
{
    // Old version:
    // unsigned short ih = i & (0xff << 8);
    // unsigned short il = i & 0xff;

    // return (ih >> 8) + (il << 8);

    // Condensed version
    return ((i & (0xff << 8)) >> 8) + ((i & 0xff) << 8);
}
