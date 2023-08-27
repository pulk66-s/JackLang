#include "ast/expr.h"

/**
 * @brief           Create a primary expression AST node.
 * @param   cpt     The current program cpt.
 * @return          The primary expression AST node.
*/
union primary_expr_ast *create_primary_expr(struct result *cpt)
{
    union primary_expr_ast *expr = malloc(sizeof(union primary_expr_ast));

    switch (cpt->datatype) {
        case RET:
            expr->ret = create_ret_ast(cpt->data);
            break;
        default:
            expr = NULL;
            break;
    }
    return expr;
}
