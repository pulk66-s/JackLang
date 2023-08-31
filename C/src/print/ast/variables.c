#include "print/ast/variables.h"
#include "print/ast/type.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_variable_decl_ast(struct variable_decl_ast *var_decl)
{
    logger().ast("\"variable_dec\": {\n");
    logger().ast("\"name\": \"%s\",\n", var_decl->name);
    print_type_ast(var_decl->type);
    print_third_expr_ast(var_decl->expr);
    logger().ast("},\n");
}

void print_variable_call_ast(struct variable_call_ast *var_call)
{
    logger().ast("\"variable_call\": {\n");
    logger().ast("\"name\": \"%s\",\n", var_call->name);
    logger().ast("},\n");
}
