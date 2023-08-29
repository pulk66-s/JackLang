#include "ast/operation.h"
#include "grammar.h"
#include <string.h>

/**
 * @brief       Create an operation AST node from the current program cpt.
 * @param   cpt The current program cpt.
 * @return      The operation AST node.
*/
struct operation_ast *create_operation(struct result *cpt)
{
    struct operation_cpt *op = cpt->data;
    char op_code = op->operand;
    struct secondary_expr_ast *left = create_secondary_expr(op->left);
    struct secondary_expr_ast *right = create_secondary_expr(op->right);
    struct operation_ast *ast = malloc(sizeof(struct operation_ast));

    memset(ast, 0, sizeof(struct operation_ast));
    *ast = (struct operation_ast) {
        .operand = op_code,
        .left = left,
        .right = right
    };
    return ast;
}
