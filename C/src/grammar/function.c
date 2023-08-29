#include "grammar/function.h"
#include "grammar/type.h"
#include "grammar/expr.h"

static struct result *arg_decl(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]) {
            type,
            identifier,
            comma
        },
        3
    );
}

static struct result *final_arg_decl(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]) {
            type,
            identifier
        },
        2
    );
}

static struct result *function_decl_args(struct parser *p)
{
    struct result *firsts_args = zero_or_more(p, arg_decl);
    struct result *last_arg;
    struct result *res;

    last_arg = final_arg_decl(p);
    if (firsts_args->size > 0 && !last_arg)
        return NULL;
    res = malloc(sizeof(struct result));
    res->datatype = EXPR;
    res->size = firsts_args->size + (last_arg ? 1 : 0);
    res->data = malloc(sizeof(struct result) * res->size);
    for (size_t i = 0; i < firsts_args->size; i++) {
        ((struct result *)res->data)[i] = ((struct result *)firsts_args->data)[i];
    }
    if (last_arg) {
        ((struct result *)res->data)[res->size - 1] = *last_arg;
    }
    return res;
}

static struct result *function_decl_lines(struct parser *p)
{
    return zero_or_more(p, expr);
}

struct result *function_decl(struct parser *p)
{
    struct result *res = malloc(sizeof(struct result));
    struct result *t, *name, **args, **lines;
    struct function_decl_cpt *fn = malloc(sizeof(struct function_decl_cpt));

    save(p);
    t = type(p);
    if (!t) {
        goto function_decl_error_end;
    }
    name = identifier(p);
    if (!name || !open_par(p)) {
        goto function_decl_error_end;
    }
    args = function_decl_args(p);
    if (!args || !close_par(p) || !open_curly(p)) {
        goto function_decl_error_end;
    }
    lines = function_decl_lines(p);
    if (!lines || !close_curly(p)) {
        goto function_decl_error_end;
    }
    *fn = (struct function_decl_cpt) {
        .name = name->data,
        .args = args,
        .lines = lines
    };
    delete_save(p);
    return result(fn, FUNCTION_DECL, 1);
function_decl_error_end:
    rollback(p);
    return NULL;
}
