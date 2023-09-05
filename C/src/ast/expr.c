#include "ast/expr.h"
#include "ast/constant.h"
#include "ast/operation.h"
#include "ast/expr.h"
#include "ast/function.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief           Create a primary expression AST node.
 * @param   cpt     The current program cpt.
 * @return          The primary expression AST node.
*/
struct primary_expr_ast *create_primary_expr(struct result *cpt)
{
    struct primary_expr_ast *expr = malloc(sizeof(struct primary_expr_ast));

    memset(expr, 0, sizeof(struct primary_expr_ast));
    switch (cpt->datatype) {
        case FUNCTION_DECL:
            expr->type = AST_PRIMARY_EXPR_FUNCTION_DECL;
            expr->u.fn_decl = create_function_decl(cpt);
            break;
        case EXPR:
            expr = create_primary_expr(cpt->data);
            break;
        default:
            expr = NULL;
            break;
    }
    return expr;
}

/**
 * @brief       Create a secondary expression AST node.
 * @param   cpt The current program cpt.
 * @return      The secondary expression AST node.
*/
struct secondary_expr_ast *create_secondary_expr(struct result *cpt)
{
    struct secondary_expr_ast *expr = malloc(sizeof(struct secondary_expr_ast));

    memset(expr, 0, sizeof(struct secondary_expr_ast));
    printf("create_secondary_expr: cpt->datatype = %d\n", cpt->datatype);
    switch (cpt->datatype) {
        case RET:
            expr->type = AST_SECONDARY_EXPR_RET;
            expr->u.ret = create_ret_ast(cpt);
            break;
        case EXPR:
            expr = create_secondary_expr(cpt->data);
            break;
        case VARIABLE_DECL:
            expr->type = AST_SECONDARY_VAR_DECL;
            expr->u.var_decl = create_variable_decl_ast(cpt);
            break;
        case CONDITION:
            expr->type = AST_SECONDARY_EXPR_COND;
            expr->u.condition = create_condition(cpt);
            break;
        case LOOP:
            expr->type = AST_SECONDARY_LOOP;
            expr->u.loop = create_loop_ast(cpt);
            break;
        default:
            printf("create_secondary_expr: unknown type %d\n", cpt->datatype);
            expr = NULL;
            break;
    }
    return expr;
}

/**
 * @brief           Create a third expression ast node.
 * @param   cpt     The current program cpt.
 * @return          The third expression ast node.
*/
struct third_expr_ast *create_third_expr(struct result *cpt)
{
    struct third_expr_ast *expr = malloc(sizeof(struct third_expr_ast));

    memset(expr, 0, sizeof(struct third_expr_ast));
    switch (cpt->datatype) {
        case OPERATION:
            expr->type = AST_THIRD_EXPR_OPERATION;
            expr->u.operation = create_operation(cpt);
            break;
        case NUMBER:
            expr->type = AST_THIRD_EXPR_CONSTANT;
            expr->u.constant = create_constant(cpt);
            break;
        case VAR:
            expr->type = AST_THIRD_EXPR_VAR_CALL;
            expr->u.var_call = create_variable_call_ast(cpt);
            break;
        case EXPR:
            expr = create_third_expr(cpt->data);
            break;
        case COMPARISON:
            expr->type = AST_THIRD_EXPR_COMPARISON;
            expr->u.comparison = create_comparison(cpt);
            break;
        default:
            printf("create_third_expr: unknown type %d\n", cpt->datatype);
            expr = NULL;
            break;
    }
    return expr;
}
