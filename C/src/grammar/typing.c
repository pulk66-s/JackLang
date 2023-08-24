#include "grammar/typing.h"
#include "grammar/word.h"
#include <string.h>

static bool existing_type(const char *type)
{
    if (strcmp(type, "int") == 0) {
        return true;
    }
    return false;
}

struct result type(struct packrat *p)
{
    size_t x = p->x, y = p->y, cursor = p->cursor;
    struct result w = word(p);

    if (!w.success) {
        return FAIL_RESULT;
    }

    char *data = w.data;

    if (!existing_type(data)) {
        p->x = x;
        p->y = y;
        p->cursor = cursor;
        return FAIL_RESULT;
    }
    return (struct result) {
        .success = true,
        .size = 1,
        .data = data,
        .datatype = STRING
    };
}
