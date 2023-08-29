#include "print/ast/constant.h"
#include "logger.h"

void print_constant_ast(struct constant_ast *constant)
{
    logger().ast("\"constant\": {\n");
    if (constant->u.int32) {
        logger().ast("\"int32\": %d,\n", constant->u.int32);
    }
    logger().ast("},\n");
}
