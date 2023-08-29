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
        print_secondary_expr_ast(operation->left);
    } else {
        logger().ast("\"error\": \"left operand is null\",\n");
        return;
    }
    if (operation->right) {
        print_secondary_expr_ast(operation->right);
    } else {
        logger().ast("\"error\": \"right operand is null\",\n");
        return;
    }
    logger().ast("},\n");
}
