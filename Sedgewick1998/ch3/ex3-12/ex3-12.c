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