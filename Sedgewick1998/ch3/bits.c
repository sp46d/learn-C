#include "bits.h"
#include <stdbool.h>
#include <stdio.h>

void setbit(unsigned int a[], int k)
{
    unsigned int flag = 1;
    size_t num_bits = sizeof(unsigned int) * 8;
    int i = k / num_bits;
    int pos = k % num_bits;
    a[i] |= flag << pos;
}

void clearbit(unsigned int a[], int k)
{
    unsigned int flag = 1;
    size_t num_bits = sizeof(unsigned int) * 8;
    int i = k / num_bits;
    int pos = k % num_bits;
    a[i] &= ~(flag << pos);
}

bool testbit(unsigned int a[], int k)
{
    unsigned int flag = 1;
    size_t num_bits = sizeof(unsigned int) * 8;
    int i = k / num_bits;
    int pos = k % num_bits;
    return a[i] & (flag << pos);
}