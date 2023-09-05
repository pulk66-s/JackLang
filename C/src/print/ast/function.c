#include "print/ast/function.h"
#include "print/ast/type.h"
#include "print/ast/expr.h"
#include "logger.h"

void print_function_decl_ast(struct function_decl_ast *fn_decl)
{
    logger().ast("\"function_decl\": {\n");
    print_type_ast(fn_decl->type);
    logger().ast("\"name\": \"%s\",\n", fn_decl->name);
    logger().ast("\"args\": [\n");
    for (size_t i = 0; fn_decl->args[i]; i++) {
        logger().ast("{\n");
        print_type_ast(fn_decl->args[i]->type);
        logger().ast("\"name\": \"%s\"\n", fn_decl->args[i]->name);
        logger().ast("},\n");
    }
    logger().ast("],\n");
    logger().ast("\"lines\": [\n");
    for (size_t i = 0; fn_decl->lines[i]; i++) {
        logger().ast("{\n");
        print_secondary_expr_ast(fn_decl->lines[i]);
        logger().ast("},\n");
    }
    logger().ast("],\n");
    logger().ast("},\n");
}
