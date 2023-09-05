#ifndef __CL_AST_CONDITION_H__
#define __CL_AST_CONDITION_H__

#include "grammar.h"
#include "ast/expr.h"

struct condition_ast {
    struct third_expr_ast *cond;
    struct secondary_expr_ast **then;
    struct secondary_expr_ast **else_;
};

struct condition_ast *create_condition(struct result *cpt);

#endif
