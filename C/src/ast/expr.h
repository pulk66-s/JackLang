#ifndef __CL_AST_EXPR_H__
#define __CL_AST_EXPR_H__

#include "ast/ret.h"
#include "ast/loop.h"
#include "ast/comparison.h"
#include "ast/operation.h"
#include "ast/constant.h"
#include "ast/variables.h"
#include "ast/condition.h"
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
    AST_SECONDARY_VAR_DECL,
    AST_SECONDARY_EXPR_COND,
    AST_SECONDARY_LOOP,
    AST_SECONDARY_EXPR_VAR_REDECL,
    AST_SECONDARY_EXPR_FN_CALL
};

struct secondary_expr_ast {
    enum ast_secondary_expr_type type;
    union {
        struct ret_ast *ret;
        struct variable_decl_ast *var_decl;
        struct condition_ast *condition;
        struct loop_ast *loop;
        struct variable_redecl_ast *var_redecl;
        struct function_call_ast *fn_call;
    } u;
};

enum ast_third_expr_type {
    AST_THIRD_EXPR_OPERATION,
    AST_THIRD_EXPR_CONSTANT,
    AST_THIRD_EXPR_VAR_CALL,
    AST_THIRD_EXPR_COMPARISON,
    AST_THIRD_EXPR_FN_CALL
};

struct third_expr_ast {
    enum ast_third_expr_type type;
    union {
        struct operation_ast *operation;
        struct constant_ast *constant;
        struct variable_call_ast *var_call;
        struct comparison_ast *comparison;
        struct function_call_ast *fn_call;
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
