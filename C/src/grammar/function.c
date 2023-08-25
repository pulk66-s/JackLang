#include "grammar/function.h"
#include "grammar/typing.h"
#include "grammar/word.h"
#include "grammar/default.h"
#include "grammar/letters.h"
#include "grammar/name.h"
#include "grammar/expr.h"
#include <stdlib.h>
#include <stdio.h>

static struct result maybe_comma(struct packrat *p)
{
    return zero_or_one(p, comma);
}

static struct result function_arg_decl(struct packrat *p)
{
    struct result res = sequence(
        p,
        (expr_t[]) {
            type,
            name,
            maybe_comma
        },
        3
    );

    if (!res.success) {
        return FAIL_RESULT;
    }

    struct result *datas = res.data;
    struct arg *arg = malloc(sizeof(struct arg));
    struct result *type_res = &datas[0];
    struct result *name_res = &datas[1];

    *arg = (struct arg) {
        .type = type_res->data,
        .name = name_res->data
    };
    return (struct result) {
        .success = true,
        .size = 1,
        .data = arg,
        .datatype = ARG_DECL
    };
}

static struct result function_args_decl(struct packrat *p)
{
    struct result res = zero_or_more(p, function_arg_decl);

    res.datatype = ARG_DECL;
    return res;
}

static struct result function_decl_lines(struct packrat *p)
{
    struct result res = zero_or_more(p, expr);

    res.datatype = EXPR_STATEMENT;
    return res;
}

struct result function_decl(struct packrat *p)
{
    struct result res = sequence(
        p,
        (expr_t[]) {
            type,
            word,
            open_par,
            function_args_decl,
            close_par,
            open_curly,
            function_decl_lines,
            close_curly
        },
        8
    );
    struct function *fn = malloc(sizeof(struct function));
    struct result *type_res, *name_res, *args_res, *exprs_res;
    struct result *datas = res.data;

    if (!res.success) {
        return FAIL_RESULT;
    }
    type_res = &datas[0];
    name_res = &datas[1];
    args_res = &datas[3];
    exprs_res = &datas[6];
    *fn = (struct function) {
        .type = type_res->data,
        .name = name_res->data,
        .args = args_res,
        .body = exprs_res
    };
    return (struct result) {
        .success = true,
        .size = 1,
        .data = fn,
        .datatype = FUNCTION_DECL
    };
}
