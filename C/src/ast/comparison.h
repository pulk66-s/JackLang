#ifndef __CL_AST_COMPARISON_H__
#define __CL_AST_COMPARISON_H__

#include "ast.h"

enum comparison_operand_ast {
    COMPARISON_OPERAND_NONE,
    COMPARISON_OPERAND_EQUAL,
    COMPARISON_OPERAND_NOT_EQUAL,
    COMPARISON_OPERAND_GREATER,
    COMPARISON_OPERAND_LESS,
    COMPARISON_OPERAND_GREATER_EQUAL,
    COMPARISON_OPERAND_LESS_EQUAL
};

struct comparison_ast {
    enum comparison_operand_ast operand;
    struct third_expr_ast *left;
    struct third_expr_ast *right;
};

struct comparison_ast *create_comparison(struct result *cpt);

#endif
