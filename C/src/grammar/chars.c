#include "grammar/chars.h"
#include <stdio.h>

struct result terminate_char(struct packrat *p)
{
    char c = next(p);

    if (c == ';') {
        return (struct result) {
            .data = ";",
            .size = 0,
            .datatype = CHAR,
            .success = true
        };
    }
    return FAIL_RESULT;
}
