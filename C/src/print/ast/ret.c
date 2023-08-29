#include "print/ast/ret.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_ret_ast(struct ret_ast *ast)
{
    logger().ast("\"ret\": {\n");
    if (ast->expr) {
        print_secondary_expr_ast(ast->expr);
    }
    logger().ast("},\n");
}
