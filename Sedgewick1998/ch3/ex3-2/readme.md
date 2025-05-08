# Exercise 3.2

Test the random-number generator on your system by generating `N` random integers between `0` and `r-1` with `rand() % r` and computing the average and standard deviation for `r = 10, 100, 1000` and `N = 1e3, 1e4, 1e5, 1e6`.

## My answer

As the author suggested in the book, I structure my program into three files.

1. Interface ([`randnum.h`](./randnum.h))
2. Implementation ([`randnum.c`](./randnum.c))
3. Client ([`ex3-2.c`](./ex3-2.c))

Below are the outputs:

```
$ clang -o ex3-2 randnum.c ex3-2.c
$ ./ex3-2
r = 10, N = 1000: Average = 4.471001, Std. Dev. = 2.78695
r = 10, N = 10000: Average = 4.485250, Std. Dev. = 2.86596
r = 10, N = 100000: Average = 4.501131, Std. Dev. = 2.86087
r = 10, N = 1000000: Average = 4.498810, Std. Dev. = 2.87631
r = 100, N = 1000: Average = 49.308941, Std. Dev. = 29.0246
r = 100, N = 10000: Average = 49.243134, Std. Dev. = 28.9147
r = 100, N = 100000: Average = 49.361294, Std. Dev. = 28.9035
r = 100, N = 1000000: Average = 49.489933, Std. Dev. = 28.8226
r = 1000, N = 1000: Average = 487.170288, Std. Dev. = 291.58
r = 1000, N = 10000: Average = 498.756348, Std. Dev. = 288.744
r = 1000, N = 100000: Average = 499.954376, Std. Dev. = 289.721
r = 1000, N = 1000000: Average = 499.665436, Std. Dev. = 288.481
```
