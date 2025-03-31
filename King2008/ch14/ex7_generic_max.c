#include <stdio.h>
#define GENERIC_MAX(type)                                                      \
    type type##_max(type x, type y) { return x > y ? x : y; }

GENERIC_MAX(long);
// which gets expanded as follows by the preprocessor:
// long long_max(long x, long y) { return x > y ? x : y; }

// GENERIC_MAX(unsigned long);
// This doesn't work because the type has a blank in its name. When "unsigned
// long" is passed to the macro, the name of the function will get defined as
// "long" because of the blank that precedes it, and its type will get decalred
// as "unsigned long unsigned", with "unsigned" unnecessarily declared twice,
// causing the compiler to raise error.

// One solution might be to use typedef to re-define the type "unsigned long"
// with a new name that has no blank in it, like below:
typedef unsigned long ulong;
GENERIC_MAX(ulong); // now it works!

int main(void)
{
    ulong x = 10;
    ulong y = 100;
    printf("x = %ld, y = %ld\n", x, y);
    printf("unsigned_long_max(x, y) = %lu\n", ulong_max(x, y));
    return 0;
}
