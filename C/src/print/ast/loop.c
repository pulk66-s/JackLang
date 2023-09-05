#include "print/ast/loop.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_ast_loop(struct loop_ast *loop)
{
    logger().ast("\"loop\": {\n");
    if (loop->condition) {
        logger().ast("\"condition\": {\n");
        print_third_expr_ast(loop->condition);
        logger().ast("},\n");
    } else {
        logger().ast("\"condition\": null,\n");
    }
    if (loop->increment) {
        logger().ast("\"increment\": {\n");
        print_third_expr_ast(loop->increment);
        logger().ast("},\n");
    } else {
        logger().ast("\"increment\": null,\n");
    }
    if (loop->init) {
        logger().ast("\"init\": {\n");
        print_third_expr_ast(loop->init);
        logger().ast("},\n");
    } else {
        logger().ast("\"init\": null,\n");
    }
    logger().ast("\"body\": [\n");
    for (size_t i = 0; loop->body[i]; i++) {
        logger().ast("{\n");
        print_secondary_expr_ast(loop->body[i]);
        logger().ast("},\n");
    }
    logger().ast("]\n");
    logger().ast("},\n");
}
