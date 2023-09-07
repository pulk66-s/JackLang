#include "print/ast/expr.h"
#include "print/ast/ret.h"
#include "print/ast/constant.h"
#include "print/ast/operation.h"
#include "print/ast/function.h"
#include "print/ast/variables.h"
#include "print/ast/condition.h"
#include "print/ast/comparison.h"
#include "print/ast/loop.h"
#include "logger.h"
#include <stdio.h>

void print_primary_expr_ast(struct primary_expr_ast *expr)
{
    logger().ast("\"primary_expr\": {\n");
    if(!expr) {
        logger().ast("\"error\": \"null primary expression\",\n");
        logger().ast("},\n");
        return;
    }
    switch (expr->type) {
        case AST_PRIMARY_EXPR_FUNCTION_DECL:
            print_function_decl_ast(expr->u.fn_decl);
            break;
        default:
            logger().ast("\"error\": \"unknown primary expression\",\n");
            break;
    }
    logger().ast("},\n");
}

void print_secondary_expr_ast(struct secondary_expr_ast *expr)
{
    logger().ast("\"secondary_expr\": {\n");
    if (!expr) {
        logger().ast("\"error\": \"null secondary expression\",\n");
        logger().ast("},\n");
        return;
    }
    switch (expr->type) {
        case AST_SECONDARY_EXPR_RET:
            print_ret_ast(expr->u.ret);
            break;
        case AST_SECONDARY_VAR_DECL:
            print_variable_decl_ast(expr->u.var_decl);
            break;
        case AST_SECONDARY_EXPR_COND:
            print_ast_condition(expr->u.condition);
            break;
        case AST_SECONDARY_LOOP:
            print_ast_loop(expr->u.loop);
            break;
        case AST_SECONDARY_EXPR_VAR_REDECL:
            print_variable_redecl_ast(expr->u.var_redecl);
            break;
        case AST_SECONDARY_EXPR_FN_CALL:
            print_function_call_ast(expr->u.fn_call);
            break;
        default:
            logger().ast("\"error\": \"unknown secondary expression %d\",\n", expr->type);
            break;
    }
    logger().ast("},\n");
}

void print_third_expr_ast(struct third_expr_ast *expr)
{
    logger().ast("\"third_expr\": {\n");
    if (!expr) {
        logger().ast("\"error\": \"null third expression\",\n");
        logger().ast("},\n");
        return;
    }
    switch (expr->type) {
        case AST_THIRD_EXPR_OPERATION:
            print_operation_ast(expr->u.operation);
            break;
        case AST_THIRD_EXPR_CONSTANT:
            print_constant_ast(expr->u.constant);
            break;
        case AST_THIRD_EXPR_VAR_CALL:
            print_variable_call_ast(expr->u.var_call);
            break;
        case AST_THIRD_EXPR_COMPARISON:
            print_comparison_ast(expr->u.comparison);
            break;
        case AST_THIRD_EXPR_FN_CALL:
            print_function_call_ast(expr->u.fn_call);
            break;
        default:
            logger().ast("\"error\": \"unknown third expression %d\",\n", expr->type);
            break;
    }
    logger().ast("},\n");
}
