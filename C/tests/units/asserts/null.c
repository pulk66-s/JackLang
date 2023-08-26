#include "units/asserts/null.h"
#include <stdlib.h>

bool assert_null(void *ptr)
{
    return ptr == NULL;
}

bool assert_not_null(void *ptr)
{
    return ptr != NULL;
}
