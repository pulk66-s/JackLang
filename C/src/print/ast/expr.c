#include "print/ast/expr.h"
#include "print/ast/ret.h"
#include "print/ast/constant.h"
#include "print/ast/operation.h"
#include "logger.h"

void print_primary_expr_ast(struct primary_expr_ast *expr)
{
    logger().ast("\"primary_expr\": {\n");
    if (!expr) {
        logger().ast("\"error\": \"null primary expression\",\n");
        logger().ast("},\n");
        return;
    }
    switch (expr->type) {
        case AST_PRIMARY_EXPR_RET:
            print_ret_ast(expr->u.ret);
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
        case AST_SECONDARY_EXPR_OPERATION:
            print_operation_ast(expr->u.operation);
            break;
        case AST_SECONDARY_EXPR_CONSTANT:
            print_constant_ast(expr->u.constant);
            break;
        default:
            logger().ast("\"error\": \"unknown secondary expression\",\n");
            break;
    }
    logger().ast("},\n");
}
