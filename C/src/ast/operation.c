#include "ast/operation.h"
#include "grammar.h"

/**
 * @brief       Create an operation AST node from the current program cpt.
 * @param   cpt The current program cpt.
 * @return      The operation AST node.
*/
struct operation_ast *create_operation(struct result *cpt)
{
    struct operation_cpt *op = cpt->data;
    char op_code = op->operand;
    union secondary_expr_ast *left = create_secondary_expr(cpt);
    union secondary_expr_ast *right = create_secondary_expr(cpt);
    struct operation_ast *ast = malloc(sizeof(struct operation_ast));

    *ast = (struct operation_ast) {
        .operand = op_code,
        .left = left,
        .right = right
    };
    return ast;
}
