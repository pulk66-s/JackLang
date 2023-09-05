#include "print/ast/program.h"
#include "print/ast/line.h"
#include "logger.h"

void print_ast_program(struct program_ast *program)
{
    logger().ast("{\n\"AST_PRGM\": {\n");
    logger().ast("\"lines\": [\n");
    for (size_t i = 0; program->lines[i]; i++) {
        logger().ast("{\n");
        print_line_ast(program->lines[i]);
        logger().ast("},\n");
    }
    logger().ast("]\n");
    logger().ast("}\n}\n");
}
