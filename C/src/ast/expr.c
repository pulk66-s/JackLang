#include "ast/expr.h"
#include "ast/constant.h"
#include "ast/operation.h"

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

/**
 * @brief       Create a secondary expression AST node.
 * @param   cpt The current program cpt.
 * @return      The secondary expression AST node.
*/
union secondary_expr_ast *create_secondary_expr(struct result *cpt)
{
    union secondary_expr_ast *expr = malloc(sizeof(union secondary_expr_ast));

    switch (cpt->datatype) {
        case OPERATION:
            expr->operation = create_operation(cpt);
            break;
        case NUMBER:
            expr->constant = create_constant(cpt);
            break;
        default:
            expr = NULL;
            break;
    }
    return expr;
}
