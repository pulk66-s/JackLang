#ifndef __CL_AST_FUNCTION_H__
#define __CL_AST_FUNCTION_H__

#include "grammar.h"
#include "ast/expr.h"
#include "ast/type.h"

struct function_decl_arg_ast {
    enum type_ast type;
    char *name;
};

struct function_decl_ast {
    enum type_ast type;
    char *name;
    struct function_decl_arg_ast **args;
    struct secondary_expr_ast **lines;
};

struct function_call_ast {
    char *name;
    struct third_expr_ast **args;
};

/**
 * @brief       Create a function declaration AST node from a result.
 * @param   cpt The current program cpt.
 * @return      The function declaration AST node.
*/
struct function_decl_ast *create_function_decl(struct result *cpt);
struct function_call_ast *create_function_call(struct result *cpt);

#endif
