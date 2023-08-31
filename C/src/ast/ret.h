#ifndef __CL_AST_RET_H__
#define __CL_AST_RET_H__

#include "ast/expr.h"
#include "parsing.h"

struct ret_ast {
    struct third_expr_ast *expr;
};

/**
 * @brief       Create the return AST from the result.
 * @param   res The result.
 * @return      The return AST.
*/
struct ret_ast *create_ret_ast(struct result *res);

#endif
