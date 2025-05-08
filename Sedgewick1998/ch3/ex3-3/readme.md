# Exercise 3.3

Test the random-number generator on your system by generating `N` random numbers of type `double` between `0` and `1`, transforming them to integers between `0` and `r-1` by multiplying by `r` and truncating the result, and computing the average and standard deviation for `r = 10, 100, 1000` and `N = 1e3, 1e4, 1e5, 1e6`.

## My answer

The overall structure of the program for this exercise is mostly the same as the one for Exercise 3.2, except that now the random number generator generates numbers of type `double`, instead of `int`, and the generated random numbers range between 0 and 1. The random numbers then get scaled to fall between `0` and `r-1`, by multiplying `r` and truncating the result. The codes to generate the desired output can be found in files (), and the output is as follows:
