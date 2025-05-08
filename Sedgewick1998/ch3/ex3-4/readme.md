# Exercise 3.4

Do Exercises 3.2 and 3.3 for `r = 2, 4, 16`.

## My answer

To do this exercise, I am going to reuse the programs that I wrote for Exercises 3.2 and 3.3 using `#include` statement. Since the programs that I am going to use are in different directories than the one where the client file resides, I am going to use relative path to include the programs. Thus, all we have to do is to update the client file, leaving the interface and implementation of the previous programs unchanged. The output is as below:

```
$ clang -o ex3_4_randnum ex3-4_randnum.c ../ex3-2/randnum.c
$ ./ex3_4_randnum
[Ex3-2: randnum] r = 2, N = 1000: Average = 0.520997, Std. Dev. = 0.499559
[Ex3-2: randnum] r = 2, N = 10000: Average = 0.498271, Std. Dev. = 0.499997
[Ex3-2: randnum] r = 2, N = 100000: Average = 0.500722, Std. Dev. = 0.499999
[Ex3-2: randnum] r = 2, N = 1000000: Average = 0.503531, Std. Dev. = 0.499988
[Ex3-2: randnum] r = 4, N = 1000: Average = 1.500003, Std. Dev. = 1.13753
[Ex3-2: randnum] r = 4, N = 10000: Average = 1.506862, Std. Dev. = 1.11891
[Ex3-2: randnum] r = 4, N = 100000: Average = 1.499146, Std. Dev. = 1.11688
[Ex3-2: randnum] r = 4, N = 1000000: Average = 1.498286, Std. Dev. = 1.12131
[Ex3-2: randnum] r = 16, N = 1000: Average = 7.664002, Std. Dev. = 4.62071
[Ex3-2: randnum] r = 16, N = 10000: Average = 7.543283, Std. Dev. = 4.59806
[Ex3-2: randnum] r = 16, N = 100000: Average = 7.469526, Std. Dev. = 4.60697
[Ex3-2: randnum] r = 16, N = 1000000: Average = 7.479467, Std. Dev. = 4.62608

$ clang -o ex3_4_randfloat ex3-4_randfloat.c ../ex3-2/randfloat.c
$ ./ex3_4_randfloat
[Ex3-3: randfloat] r = 2, N = 1000: Average = 0.509997, Std. Dev. = 0.4999
[Ex3-3: randfloat] r = 2, N = 10000: Average = 0.495671, Std. Dev. = 0.499981
[Ex3-3: randfloat] r = 2, N = 100000: Average = 0.504016, Std. Dev. = 0.499984
[Ex3-3: randfloat] r = 2, N = 1000000: Average = 0.502986, Std. Dev. = 0.499991
[Ex3-3: randfloat] r = 4, N = 1000: Average = 1.540002, Std. Dev. = 1.11552
[Ex3-3: randfloat] r = 4, N = 10000: Average = 1.514762, Std. Dev. = 1.11937
[Ex3-3: randfloat] r = 4, N = 100000: Average = 1.497546, Std. Dev. = 1.11716
[Ex3-3: randfloat] r = 4, N = 1000000: Average = 1.499395, Std. Dev. = 1.12168
[Ex3-3: randfloat] r = 16, N = 1000: Average = 7.868000, Std. Dev. = 4.64117
[Ex3-3: randfloat] r = 16, N = 10000: Average = 7.554308, Std. Dev. = 4.60014
[Ex3-3: randfloat] r = 16, N = 100000: Average = 7.496357, Std. Dev. = 4.60787
[Ex3-3: randfloat] r = 16, N = 1000000: Average = 7.481364, Std. Dev. = 4.62685
```
