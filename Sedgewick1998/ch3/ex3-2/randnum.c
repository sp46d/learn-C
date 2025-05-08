#include "randnum.h"
#include <stdlib.h>

Number randnum(int min, int max)
{
    Number r = rand() % max;
    return r < min ? r + min : r;
}