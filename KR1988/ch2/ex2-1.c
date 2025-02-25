// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <stdio.h>
#include <limits.h>

typedef enum
{
    CHAR,
    SHORT,
    INT,
    LONG,
} dtype;

// function prototype
void use_header(void);
void compute_range(void);
int num_bit(dtype t);

int main(void)
{
    printf("1. With 'limits.h': \n\n");
    use_header();
    printf("\n");
    printf("2. By direct computation: \n\n");
    compute_range();
    return 0;
}

void use_header(void)
{
    printf("  The range of 'signed char': (%d, %d)\n", SCHAR_MIN, SCHAR_MAX);
    printf("  The range of 'unsigned char': (0, %d)\n", UCHAR_MAX);
    printf("  The range of 'signed short': (%d, %d)\n", SHRT_MIN, SHRT_MAX);
    printf("  The range of 'unsigned short': (0, %d)\n", USHRT_MAX);
    printf("  The range of 'signed int': (%d, %d)\n", INT_MIN, INT_MAX);
    printf("  The range of 'unsigned int': (0, %u)\n", UINT_MAX);
    printf("  The range of 'signed long': (%ld, %ld)\n", LONG_MIN, LONG_MAX);
    printf("  The range of 'unsigned long': (0, %lu)\n", ULONG_MAX);
}

void compute_range(void)
{

    int char_bit = num_bit(CHAR);   // 8
    int short_bit = num_bit(SHORT); // 16
    int int_bit = num_bit(INT);     // 32
    int long_bit = num_bit(LONG);   // 64

    printf("  The range of 'signed char': (%d, %d)\n", -(1 << (char_bit - 1)), (1 << (char_bit - 1)) - 1);
    printf("  The range of 'unsigned char': (0, %d)\n", (1 << (char_bit - 1)) + ((1 << (char_bit - 1)) - 1));
    printf("  The range of 'signed short': (%d, %d)\n", -(1 << (short_bit - 1)), (1 << (short_bit - 1)) - 1);
    printf("  The range of 'unsigned short': (0, %d)\n", (1 << (short_bit - 1)) + ((1 << (short_bit - 1)) - 1));
    printf("  The range of 'signed int': (%d, %d)\n", 1 << (int_bit - 1), (1 << (int_bit - 1)) - 1);
    printf("  The range of 'unsigned int': (0, %u)\n", (1 << (int_bit - 1)) + ((1 << (int_bit - 1)) - 1));
    printf("  The range of 'signed long': (%ld, %ld)\n", 1L << (long_bit - 1), (1L << (long_bit - 1)) - 1);
    printf("  The range of 'unsigned long': (0, %lu)\n", (1LU << (long_bit - 1)) + ((1LU << (long_bit - 1)) - 1));
}

int num_bit(dtype t)
{
    char c;
    short s;
    int i;
    long l;

    int n;

    if (t == CHAR)
    {
        for (n = 0; c != -1; n++)
        {
            c = 1;
            c <<= n;
            c += (c - 1);
        }
    }
    else if (t == SHORT)
    {
        for (n = 0; s != -1; n++)
        {
            s = 1;
            s <<= n;
            s += (s - 1);
        }
    }
    else if (t == INT)
    {
        for (n = 0; i != -1; n++)
        {
            i = 1;
            i <<= n;
            i += (i - 1);
        }
    }
    else if (t == LONG)
    {
        for (n = 0; l != -1; n++)
        {
            l = 1;
            l <<= n;
            l += (l - 1);
        }
    }
    return n;
}