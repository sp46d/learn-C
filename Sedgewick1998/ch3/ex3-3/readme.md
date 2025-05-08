# Exercise 3.3

Test the random-number generator on your system by generating `N` random numbers of type `double` between `0` and `1`, transforming them to integers between `0` and `r-1` by multiplying by `r` and truncating the result, and computing the average and standard deviation for `r = 10, 100, 1000` and `N = 1e3, 1e4, 1e5, 1e6`.

## My answer

The overall structure of the program for this exercise is mostly the same as the one for Exercise 3.2, except that now the random number generator generates numbers of type `double`, instead of `int`, and the generated random numbers range between 0 and 1. The random numbers then get scaled to fall between `0` and `r-1`, by multiplying `r` and truncating the result. The codes to generate the desired output can be found in files ([`randfloat.h`](./randfloat.h), [`randfloat.c`](./randfloat.c), [`ex3-3.c`](./ex3-3.c)), and the output is as follows:

```
$ clang -o ex3-3 randfloat.c ex3-3.c
$ ./ex3-3
r = 10, N = 1000: Average = 4.518999, Std. Dev. = 2.91093
r = 10, N = 10000: Average = 4.518047, Std. Dev. = 2.88457
r = 10, N = 100000: Average = 4.511760, Std. Dev. = 2.87123
r = 10, N = 1000000: Average = 4.498168, Std. Dev. = 2.8789
r = 100, N = 1000: Average = 50.247952, Std. Dev. = 28.8688
r = 100, N = 10000: Average = 49.619141, Std. Dev. = 29.1059
r = 100, N = 100000: Average = 49.479122, Std. Dev. = 28.8601
r = 100, N = 1000000: Average = 49.477928, Std. Dev. = 28.8365
r = 1000, N = 1000: Average = 496.510193, Std. Dev. = 291.915
r = 1000, N = 10000: Average = 500.999481, Std. Dev. = 288.082
r = 1000, N = 100000: Average = 498.676453, Std. Dev. = 288.463
r = 1000, N = 1000000: Average = 498.846130, Std. Dev. = 288.609
```
