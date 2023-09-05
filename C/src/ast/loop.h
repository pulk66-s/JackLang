#ifndef __CL_AST_LOOP_H__
#define __CL_AST_LOOP_H__

#include "grammar.h"
#include "ast/expr.h"

struct loop_ast {
    struct third_expr_ast *condition;
    struct third_expr_ast *increment;
    struct third_expr_ast *init;
    struct secondary_expr_ast **body;
};

struct loop_ast *create_loop_ast(struct result *r);

#endif