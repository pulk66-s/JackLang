#ifndef __CL_AST_EXPR_H__
#define __CL_AST_EXPR_H__

#include "ast/ret.h"
#include "ast/operation.h"
#include "ast/constant.h"
#include "parsing/manager.h"

enum ast_primary_expr_type {
    AST_PRIMARY_EXPR_FUNCTION_DECL
};

struct primary_expr_ast {
    enum ast_primary_expr_type type;
    union {
        struct ret_ast *fn_decl;
    } u;
};

enum ast_secondary_expr_type {
    AST_SECONDARY_EXPR_RET = 42
};

struct secondary_expr_ast {
    enum ast_secondary_expr_type type;
    union {
        struct ret_ast *ret;
    } u;
};

enum ast_third_expr_type {
    AST_THIRD_EXPR_OPERATION,
    AST_THIRD_EXPR_CONSTANT
};

struct third_expr_ast {
    enum ast_third_expr_type type;
    union {
        struct operation_ast *operation;
        struct constant_ast *constant;
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
