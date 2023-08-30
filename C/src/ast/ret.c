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
    struct return_cpt *cpt = res->data;

    *ret = (struct ret_ast) {
        .expr = create_third_expr(cpt->expr)
    };
    return ret;
}
