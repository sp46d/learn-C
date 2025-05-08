#include "randfloat.h"
#include <stdlib.h>

Number randfloat(void) { return (float)rand() / RAND_MAX; }