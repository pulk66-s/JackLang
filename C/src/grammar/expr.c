#include "grammar/types.h"
#include "grammar/default.h"
#include "grammar/word.h"
#include "grammar/chars.h"
#include "grammar/expr.h"
#include "grammar/operation/basic.h"
#include <stdlib.h>
#include <stdio.h>

static struct result primary_expr(struct packrat *p)
{
    return operation(p);
}

static struct result expr_statement(struct packrat *p)
{
    struct result res = sequence(
        p,
        (expr_t[]) {
            primary_expr,
            terminate_char
        },
        2
    );

    if (!res.success) {
        return res;
    }

    struct result *datas = res.data;
    struct result *data = &datas[0];
    struct result *terminated = &datas[1];
    struct expr *expr = malloc(sizeof(struct expr));

    *expr = (struct expr) {
        .data = data,
        .terminate = *(char *)terminated->data
    };
    return (struct result) {
        .data = expr,
        .success = res.success,
        .datatype = EXPR_STATEMENT,
        .size = 1
    };
}

struct result expr(struct packrat *p)
{
    return expr_statement(p);
}
