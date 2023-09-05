#include "print/ast/constant.h"
#include "logger.h"

void print_constant_ast(struct constant_ast *constant)
{
    logger().ast("\"constant\": {\n");
    switch (constant->type) {
        case INT32:
            logger().ast("\"type\": \"int32\",\n");
            break;
        default:
            logger().ast("\"type\": \"unknown\",\n");
            break;
    }
    logger().ast("\"value\": %d\n", constant->u.int32);
    logger().ast("},\n");
}
