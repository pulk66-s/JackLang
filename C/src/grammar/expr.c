#include "grammar/operation.h"
#include "grammar/function.h"
#include "grammar/expr.h"
#include "grammar/ret.h"
#include "grammar/comparison.h"
#include "grammar/variables.h"
#include "grammar/loop.h"
#include "parsing.h"

struct result *primary_expression(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            function_decl
        },
        1
    );
}

struct result *secondary_expression(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            ret,
            variable_declaration,
        },
        2
    );
}

struct result *secondary_expression_without_endchar(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            condition,
            loop
        },
        2
    );
}


struct result *third_expression(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            comparison,
            operation
        },
        2
    );
}

struct result *expr_value(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]){
            number,
            identifier,
        },
        2
    );
}

static struct result *expr_stmt(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]){
            secondary_expression,
            semicolon,
        },
        2
    );
}

struct result *expr(struct parser *p)
{
    save(p);

    struct result *r = ordered_choice(
        p,
        (parser_func[]){
            secondary_expression_without_endchar,
            expr_stmt,
        },
        2
    );

    if (!r) {
        rollback(p);
        return NULL;
    }
    delete_save(p);
    return result(r, EXPR, 1);
}
