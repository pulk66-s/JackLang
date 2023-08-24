#include "grammar/types.h"
#include "grammar/default.h"
#include "grammar/word.h"
#include "grammar/chars.h"
#include "grammar/expr.h"
#include <stdlib.h>

static struct result terminated_line(struct packrat *p)
{
    struct result res = sequence(p, (expr_t[]) {word, terminate_char}, 2);
    struct expr *e = malloc(sizeof(struct expr));

    if (!res.success) {
        return FAIL_RESULT;
    }

    char *word = (char *)((struct result *)res.data)[0].data;
    char terminate = *(char *)((struct result *)res.data)[1].data;

    *e = (struct expr) {
        .name = word,
        .terminate = terminate,
    };
    return (struct result) {
        .success = true,
        .data = e,
        .datatype = EXPR,
        .size = 1
    };
}

struct result expr(struct packrat *p)
{
    return terminated_line(p);
}
