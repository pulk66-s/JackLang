#include "print/ast/type.h"
#include "logger.h"

void print_type_ast(enum type_ast type)
{
    switch (type) {
        case INT_TYPE_AST:
            logger().ast("\"type\": \"int\",\n");
            break;
        default:
            logger().ast("UNKNOWN_TYPE_AST");
            break;
    }
}
