#include "print/expr.h"
#include "print/repartition.h"
#include "logger.h"

void print_expr(struct result *res)
{
    if (res->datatype != EXPR) {
        logger().syntax_debug("print_expr: res->datatype != EXPR");
        return;
    }
    logger().syntax("\"Expr\": [\n");
    for (size_t i = 0; i < res->size; i++) {
        struct result expr = ((struct result *)res->data)[i];

        logger().syntax("{\n");
        repartition(&expr);
        logger().syntax("},\n");
    }
    logger().syntax("],\n");
}
