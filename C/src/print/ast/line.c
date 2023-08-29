#include "print/ast/line.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_line_ast(struct line_ast *line)
{
    logger().ast("\"line\": {\n");
    print_primary_expr_ast(line->expr);
    logger().ast("},\n");
}