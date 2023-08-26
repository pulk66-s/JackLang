#include "grammar/operation.h"
#include "grammar/expr.h"
#include "parsing.h"

static struct result *expr_stmt(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]){
            operation,
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
