// Exercise 3.12 Modify our implementation of the sieve of Eratosthenes
// (Program 3.5) to use an array of (i) chars; and (ii) bits. Determine the
// effects of these changes on the amount of space and time used by the program.

#include <stdbool.h>
#include <stdio.h>
#define N 1000
void find_prime_char(char a[], int size);
void find_prime_bit(unsigned int a[], int arr_size, int max_num);
void print_prime_bit(unsigned int a[], int max_num);
void setbit(unsigned int a[], int k);
void clearbit(unsigned int a[], int k);
bool testbit(unsigned int a[], int k);

int main(void)
{
    // 1. Array of chars
    // char a[N + 1];
    // find_prime_char(a, N);
    // for (int i = 0; i <= N; i++)
    //     if (a[i])
    //         printf("%2d, ", i);
    // printf("\n");

    // 2. Array of bits
    int n = N / (sizeof(unsigned int) * 8) + 1;
    unsigned int b[n];
    find_prime_bit(b, n, N);
    print_prime_bit(b, N);

    return 0;
}

// 1. Array of chars. Although we changed from an array of ints to an array of
// chars, the algorithm still has to go through all the numbers to check if the
// given number is a prime number. Thus, its running time is still N/2 + N/3 +
// N/5 + ..., that is, O(NlogN). However, now the array we have to maintain
// throughout the loop consists of chars (1 byte each) instead of ints (4 bytes
// each), so the gain from the change is 4-fold on space.
void find_prime_char(char a[], int size)
{
    a[0] = a[1] = 0;
    for (int i = 2; i <= size; i++)
        a[i] = 1;
    for (int i = 2; i <= size; i++)
        if (a[i])
            for (int j = i; i * j <= size; j++)
                a[i * j] = 0;
}

// 2. Array of bits. Now the save on space from changing to an array of bits is
// even bigger than changing to an array of chars. Since an int takes 4 bytes,
// which is 32 bits, the save on space is now 32-fold, compared to an array of
// ints. That means, if we need to find prime numbers up to 10000, the space of
// memory we are going to need will be just 1250 bytes with an array of bits,
// instead of 40k bytes with an array of ints.
void find_prime_bit(unsigned int a[], int size, int max_num)
{
    for (int i = 0; i < size; i++)
        a[i] = ~0;
    for (int i = 2; i <= max_num; i++)
        if (testbit(a, i))
            for (int j = i; i * j <= max_num; j++)
                clearbit(a, i * j);
}

void print_prime_bit(unsigned int a[], int max_num)
{
    for (int i = 2; i <= max_num; i++)
        if (testbit(a, i))
            printf("%d ", i);
    printf("\n");
}

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