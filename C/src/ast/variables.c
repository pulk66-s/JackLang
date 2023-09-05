#include "ast/variables.h"
#include "grammar.h"
#include <stdlib.h>
#include <string.h>

struct variable_decl_ast *create_variable_decl_ast(struct result *cpt)
{
    struct variable_decl_cpt *var_decl_cpt = cpt->data;
    struct variable_decl_ast *var_decl = malloc(sizeof(struct variable_decl_ast));

    memset(var_decl, 0, sizeof(struct variable_decl_ast));
    *var_decl = (struct variable_decl_ast){
        .name = var_decl_cpt->identifier,
        .type = type_ast(var_decl_cpt->type),
        .expr = create_third_expr(var_decl_cpt->value)
    };
    return var_decl;
}

struct variable_call_ast *create_variable_call_ast(struct result *cpt)
{
    struct variable_call_ast *var_call = malloc(sizeof(struct variable_call_ast));

    memset(var_call, 0, sizeof(struct variable_call_ast));
    *var_call = (struct variable_call_ast) {
        .name = cpt->data
    };
    return var_call;
}

struct variable_redecl_ast *create_variable_redecl_ast(struct result *cpt)
{
    struct variable_redecl_cpt *var_redecl_cpt = cpt->data;
    struct variable_redecl_ast *var_redecl = malloc(sizeof(struct variable_redecl_ast));

    memset(var_redecl, 0, sizeof(struct variable_redecl_ast));
    *var_redecl = (struct variable_redecl_ast){
        .name = var_redecl_cpt->identifier,
        .expr = create_third_expr(var_redecl_cpt->value),
        .operator = var_redecl_cpt->operator
    };
    return var_redecl;
}
