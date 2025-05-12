# Exercise 3.12

Exercise 3.12 Modify our implementation of the sieve of Eratosthenes (Program 3.5) to use an array of (i) chars; and (ii) bits. Determine the effects of these changes on the amount of space and time used by the program.

## My answer

Regardless of whether we changed from an array of `int`s to an array of `char`s or to an array of `bit`s, the algorithm still has to go through all the numbers to check if the given number is a prime number. Thus, its running time is still `N/2 + N/3 + N/5 + ...`, that is, `O(NlogN)` just as the same before. However, if we choose an array of `char`s, instead of an array of `int`s, the save on space will be 4-fold, because a `char` takes 1 byte, while an `int` takes 4 bytes. This gain will get even bigger if we choose to use an array of `bit`s. Since an `int` takes 4 bytes, which is 32 bits, the save is now 32-fold. That means, if we need to find prime numbers up to 10000, the space of memory we are going to need will be just 1250 bytes with an array of `bit`s, instead of 40k bytes with an array of `int`s.
