#include "print/cpt/expr.h"
#include "print/cpt/repartition.h"
#include "logger.h"

void print_expr(struct result *res)
{
    if (res->datatype != EXPR) {
        logger().cpt_debug("print_expr: res->datatype != EXPR");
        return;
    }
    logger().cpt("\"Expr\": [\n");
    for (size_t i = 0; i < res->size; i++) {
        struct result expr = ((struct result *)res->data)[i];

        logger().cpt("{\n");
        repartition(&expr);
        logger().cpt("},\n");
    }
    logger().cpt("],\n");
}
