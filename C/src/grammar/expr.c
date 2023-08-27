#include "grammar/operation.h"
#include "grammar/expr.h"
#include "grammar/ret.h"
#include "parsing.h"

struct result *primary_expression(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            operation,
            ret
        },
        2
    );
}

struct result *secondary_expression(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            operation,
        },
        1
    );
}

static struct result *expr_stmt(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]){
            primary_expression,
            semicolon,
        },
        2
    );
}

struct result *expr(struct parser *p)
{
    save(p);

    struct result *r = expr_stmt(p);

    if (!r) {
        rollback(p);
        return NULL;
    }
    delete_save(p);
    return result(r, EXPR, 1);
}
