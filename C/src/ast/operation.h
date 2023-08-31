#ifndef __CL_AST_OPERATION_H__
#define __CL_AST_OPERATION_H__

#include "parsing.h"
#include "ast/expr.h"

struct operation_ast {
    char operand;
    struct third_expr_ast *left;
    struct third_expr_ast *right;
};

/**
 * @brief       Create an operation AST node from the current program cpt.
 * @param   cpt The current program cpt.
 * @return      The operation AST node.
*/
struct operation_ast *create_operation(struct result *cpt);

#endif
