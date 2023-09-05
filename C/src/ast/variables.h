#ifndef __CL_AST_VARIABLES_H__
#define __CL_AST_VARIABLES_H__

#include "ast/expr.h"
#include "ast/type.h"

struct variable_decl_ast {
    char *name;
    enum type_ast type;
    struct third_expr_ast *expr;
};

struct variable_call_ast {
    char *name;
};

struct variable_redecl_ast {
    char *name;
    char *operator;
    struct third_expr_ast *expr;
};

struct variable_decl_ast *create_variable_decl_ast(struct result *cpt);
struct variable_call_ast *create_variable_call_ast(struct result *cpt);
struct variable_redecl_ast *create_variable_redecl_ast(struct result *cpt);

#endif
