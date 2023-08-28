#include "ast/ret.h"
#include "ast/ret.h"
#include "parsing.h"

/**
 * @brief       Create the return AST from the result.
 * @param   res The result.
 * @return      The return AST.
*/
struct ret_ast *create_ret_ast(struct result *res)
{
    struct ret_ast *ret = malloc(sizeof(struct ret_ast));

    *ret = (struct ret_ast) {
        .expr = create_secondary_expr(res)
    };
    return NULL;
}