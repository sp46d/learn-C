#include "../bits.h"
#include <stdio.h>

void find_prime_bit(unsigned int a[], unsigned int size, unsigned int max_num);

int main(void)
{
    unsigned int Ns[] = { 1e3, 1e4, 1e5, 1e6 };
    size_t num_N = sizeof(Ns) / sizeof(Ns[0]);

    unsigned int ns[num_N];
    for (size_t i = 0; i < num_N; i++)
        ns[i] = Ns[i] / (sizeof(unsigned int) * 8) + 1;

    int n_primes;
    for (size_t i = 0; i < num_N; i++) {
        n_primes = 0;
        unsigned int a[ns[i]];
        find_prime_bit(a, ns[i], Ns[i]);
        for (size_t j = 2; j <= Ns[i]; j++)
            if (testbit(a, j))
                n_primes++;
        printf("Number of primes less than %u: %d\n", Ns[i], n_primes);
    }
    return 0;
}

void find_prime_bit(unsigned int a[], unsigned int size, unsigned int max_num)
{
    for (size_t i = 0; i < size; i++)
        a[i] = ~0;
    for (size_t i = 2; i <= max_num; i++)
        if (testbit(a, i))
            for (size_t j = i; i * j <= max_num; j++)
                clearbit(a, i * j);
}