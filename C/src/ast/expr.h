#ifndef __CL_AST_EXPR_H__
#define __CL_AST_EXPR_H__

#include "ast/ret.h"
#include "ast/operation.h"
#include "ast/constant.h"
#include "ast/variables.h"
#include "parsing/manager.h"

enum ast_primary_expr_type {
    AST_PRIMARY_EXPR_FUNCTION_DECL
};

struct primary_expr_ast {
    enum ast_primary_expr_type type;
    union {
        struct function_decl_ast *fn_decl;
    } u;
};

enum ast_secondary_expr_type {
    AST_SECONDARY_EXPR_RET,
    AST_SECONDARY_VAR_DECL
};

struct secondary_expr_ast {
    enum ast_secondary_expr_type type;
    union {
        struct ret_ast *ret;
        struct variable_decl_ast *var_decl;
    } u;
};

enum ast_third_expr_type {
    AST_THIRD_EXPR_OPERATION,
    AST_THIRD_EXPR_CONSTANT,
    AST_THIRD_EXPR_VAR_CALL
};

struct third_expr_ast {
    enum ast_third_expr_type type;
    union {
        struct operation_ast *operation;
        struct constant_ast *constant;
        struct variable_call_ast *var_call;
    } u;
};

/**
 * @brief           Create a primary expression AST node.
 * @param   cpt     The current program cpt.
 * @return          The primary expression AST node.
*/
struct primary_expr_ast *create_primary_expr(struct result *cpt);

/**
 * @brief       Create a secondary expression AST node.
 * @param   cpt The current program cpt.
 * @return      The secondary expression AST node.
*/
struct secondary_expr_ast *create_secondary_expr(struct result *cpt);

/**
 * @brief           Create a third expression ast node.
 * @param   cpt     The current program cpt.
 * @return          The third expression ast node.
*/
struct third_expr_ast *create_third_expr(struct result *cpt);

#endif
