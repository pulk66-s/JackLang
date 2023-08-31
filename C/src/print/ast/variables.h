#ifndef __CL_PRINT_AST_VARIABLES_H__
#define __CL_PRINT_AST_VARIABLES_H__

#include "ast.h"

void print_variable_decl_ast(struct variable_decl_ast *var_decl);
void print_variable_call_ast(struct variable_call_ast *var_call);

#endif