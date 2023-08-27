#ifndef __CL_AST_EXPR_H__
#define __CL_AST_EXPR_H__

#include "ast/ret.h"
#include "parsing/manager.h"

union primary_expr_ast {
    struct ret_ast *ret;
};

union secondary_expr_ast {
};

/**
 * @brief           Create a primary expression AST node.
 * @param   cpt     The current program cpt.
 * @return          The primary expression AST node.
*/
union primary_expr_ast *create_primary_expr(struct result *cpt);

#endif
