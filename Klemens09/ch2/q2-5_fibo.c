#include <stdio.h>
#define ARR_SIZE 20

void fibonacci(int arr[], size_t len);

int main(void)
{
    int fibo_seq[ARR_SIZE];
    fibonacci(fibo_seq, ARR_SIZE);
    // print header
    printf("N-th\tFibonacci\tN/(N-1)\n");
    // print the first row
    printf("%4d\t%9d\t%7s\n", 1, fibo_seq[0], "NaN");
    for (int i = 1; i < ARR_SIZE; ++i)
        printf("%4d\t%9d\t%7.4g\n", i + 1, fibo_seq[i],
            (fibo_seq[i] + 0.0) / fibo_seq[i - 1]);
    return 0;
}

void fibonacci(int arr[], size_t len)
{
    if (len <= 0) {
        printf("Error: Size of a Fibonacci sequence must be greater than 0.");
    } else if (len == 1) {
        arr[0] = 0;
    } else if (len == 2) {
        arr[0] = 0;
        arr[1] = 1;
    } else {
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < len; ++i)
            arr[i] = arr[i - 2] + arr[i - 1];
    }
    return;
}
