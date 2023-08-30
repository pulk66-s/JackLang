#include "ast/function.h"
#include "ast/expr.h"
#include "ast/type.h"
#include <stdlib.h>

static struct function_decl_arg_ast **create_function_decl_args(struct function_arg_decl_cpt **cpt_args)
{
    size_t s = 0;
    struct function_decl_arg_ast **args;

    for (; cpt_args[s]; s++);
    args = malloc(sizeof(struct function_decl_arg_ast *) * (s + 1));
    for (size_t i = 0; i < s; i++) {
        args[i] = malloc(sizeof(struct function_decl_arg_ast));
        args[i]->type = type_ast(cpt_args[i]->type);
        args[i]->name = cpt_args[i]->name;
    }
    args[s] = NULL;
    return args;
}

static struct secondary_expr_ast **create_function_decl_lines(struct result *res)
{
    struct secondary_expr_ast **lines = NULL;

    for (size_t i = 0, size = 0; i < res->size; i++) {
        struct result *r = &res->data[i];
        struct secondary_expr_ast *expr = create_secondary_expr(r);

        if (!lines) {
            lines = malloc(sizeof(struct secondary_expr_ast *) * 2);
            lines[0] = expr;
            lines[1] = NULL;
        } else {
            size_t size = 0;

            for (; lines[size]; size++);
            lines = realloc(lines, sizeof(struct secondary_expr_ast *) * (size + 2));
            lines[size] = expr;
            lines[size + 1] = NULL;
        }
    }
    return lines;
}

/**
 * @brief       Create a function declaration AST node from a result.
 * @param   cpt The current program cpt.
 * @return      The function declaration AST node.
*/
struct function_decl_ast *create_function_decl(struct result *cpt)
{
    struct function_decl_ast *fn_decl = malloc(sizeof(struct function_decl_ast));
    struct function_decl_cpt *fn_cpt = cpt->data;

    *fn_decl = (struct function_decl_ast) {
        .type = type_ast(fn_cpt->type),
        .name = fn_cpt->name,
        .args = create_function_decl_args(fn_cpt->args),
        .lines = create_function_decl_lines(fn_cpt->lines)
    };
    return fn_decl;
}