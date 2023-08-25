#include "grammar/letters.h"
#include <stdlib.h>

static inline struct result letter(struct packrat *p, char check)
{
    char c = next(p);

    if (c != check) {
        prev(p);
        return FAIL_RESULT;
    }
    
    char *buf = malloc(2);

    buf[0] = c;
    buf[1] = '\0';
    return (struct result) {
        .size = 1,
        .success = true,
        .data = buf,
        .datatype = CHAR
    };
}

struct result open_par(struct packrat *p)
{
    return letter(p, '(');
}

struct result close_par(struct packrat *p)
{
    return letter(p, ')');
}

struct result comma(struct packrat *p)
{
    return letter(p, ',');
}

struct result open_curly(struct packrat *p)
{
    return letter(p, '{');
}

struct result close_curly(struct packrat *p)
{
    return letter(p, '}');
}
