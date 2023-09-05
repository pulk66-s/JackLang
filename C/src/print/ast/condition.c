#include "print/ast/condition.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_ast_condition(struct condition_ast *ast)
{
    logger().ast("\"condition\": {\n");
    if (!ast) {
        logger().ast("\"error\": \"null condition\",\n");
        logger().ast("},\n");
        return;
    }
    logger().ast("\"cond\": {\n");
    print_third_expr_ast(ast->cond);
    logger().ast("},\n");
    logger().ast("\"then\": [\n");
    for (size_t i = 0; ast->then[i]; i++) {
        logger().ast("{\n");
        print_secondary_expr_ast(ast->then[i]);
        logger().ast("},\n");
    }
    logger().ast("],\n");
    if (ast->else_) {
        logger().ast("\"else\": [\n");
        for (size_t i = 0; ast->else_[i]; i++) {
            logger().ast("{\n");
            print_secondary_expr_ast(ast->else_[i]);
            logger().ast("},\n");
        }
        logger().ast("],\n");
    }
    logger().ast("},\n");
}
