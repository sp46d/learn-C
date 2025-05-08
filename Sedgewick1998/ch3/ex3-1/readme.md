# Exercise 3.1

Find the largest and smallest numbers that you can represent with types `int`, `long int`, `short int`, `float`, and `double` in your programming environment.

## My answer

We can use `limits.h` and `float.h` standard libraries to find the limits of those types as in [`ex3-1.c`](./ex3-1.c). And the output is as follows:

```
$ clang -o ex3-1 ex3-1.c
$ ./ex3-1
1. int (4 bytes): largest = 2147483647, smallest = -2147483648
2. long int (8 bytes): largest = 9223372036854775807, smallest = -9223372036854775808
3. short int (2 bytes): largest = 32767, smallest = -32768
4. float (4 bytes): largest = 340282346638528859811704183484516925440.000000, smallest = 0.000000
5. double (8 bytes): largest = 1.79769e+308, smallest = 2.22507e-308
```
