# Exercise 3.5

Implement the necessary functions to allow Program 3.2 to be used for random _bits_ (numbers that can take only the values 0 or 1).

## Program 3.2

```C
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Number;

Number randNum(void) { return rand(); }

int main(int argc, char *argv[])
{
    int i;
    int N = atoi(argv[1]);
    float m1 = 0.0;
    float m2 = 0.0;
    Number x;

    for (i = 0; i < N; i++) {
        x = randNum();
        m1 += ((float)x) / N;
        m2 += ((float)x * x) / N;
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));
    return 0;
}
```

# My answer

The function `itobit()` specified in below converts a number generated from `randNum()` into a bit, which takes a value either 0 or 1, so we just have to pass the value generated from `randNum()` to `itobit` to get Program 3.2 to work for random bits. To this end, the function `itobit` takes an argument of type `Number` and returns an output of type `Number`, the same type as for `randNum`.

```C
Number itobit(Number x)
{
    return x % 2;
}
```
