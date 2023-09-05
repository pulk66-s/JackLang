#include "print/ast/operation.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_operation_ast(struct operation_ast *operation)
{
    logger().ast("\"operation\": {\n");
    if (!operation) {
        logger().ast("\"error\": \"operation is null\",\n");
        return;
    }
    logger().ast("\"operator\": \"%c\",\n", operation->operand);
    if (operation->left) {
        logger().ast("\"left\": {\n");
        print_third_expr_ast(operation->left);
        logger().ast("},\n");
    } else {
        logger().ast("\"error\": \"left operand is null\",\n");
        return;
    }
    if (operation->right) {
        logger().ast("\"right\": {\n");
        print_third_expr_ast(operation->right);
        logger().ast("},\n");
    } else {
        logger().ast("\"error\": \"right operand is null\",\n");
        return;
    }
    logger().ast("},\n");
}
