#include "grammar/default.h"
#include <stdlib.h>

struct result zero_or_more(struct packrat *p, expr_t e)
{
    struct result res = {.success = true, .data = NULL};
    size_t nb_success = 0;

    while (true) {
        struct result r = e(p);

        if (!r.success) {
            break;
        }
        nb_success++;
        if (!res.data) {
            res.data = malloc(sizeof(struct result));
        } else {
            res.data = realloc(res.data, sizeof(struct result) * nb_success);
        }
        ((struct result *) res.data)[nb_success - 1] = r;
    }
    res.size = nb_success;
    return res;
}

struct result sequence(struct packrat *p, expr_t *exprs, size_t size)
{
    struct result res = DEFAULT_RESULT;
    struct result *datas = malloc(sizeof(struct result) * size);

    for (size_t i = 0; i < size; i++) {
        struct result r = exprs[i](p);

        if (!r.success) {
            return FAIL_RESULT;
        }
        datas[i] = r;
    }
    res.success = true;
    res.size = size;
    res.data = datas;
    return res;
}