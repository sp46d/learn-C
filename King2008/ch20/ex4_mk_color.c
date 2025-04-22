#include <stdio.h>

#define MK_COLOR(r, g, b) (r) + ((g) << 8) + ((b) << 16)
#define GET_RED(color) (color) & 0xff
#define GET_GREEN(color) ((color) >> 8) & 0xff
#define GET_BLUE(color) ((color) >> 16) & 0xff

int main(void)
{
    long r = 0;
    long g = 0;
    long b = 0;
    printf("Enter RGB: ");
    scanf("%ld%ld%ld", &r, &g, &b);

    long color = MK_COLOR(r, g, b);
    printf("After: %ld\n", color);
    printf("Red entered: %ld\n", GET_RED(color));
    printf("Green entered: %ld\n", GET_GREEN(color));
    printf("Blue entered: %ld\n", GET_BLUE(color));
    return 0;
}
