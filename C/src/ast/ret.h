#ifndef __CL_AST_RET_H__
#define __CL_AST_RET_H__

#include "ast/expr.h"

struct ret_ast {
    union secondary_expr_ast *expr;
};

#endif
