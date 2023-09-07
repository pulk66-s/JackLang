#ifndef __CL_PRINT_AST_FUNCTION_H__
#define __CL_PRINT_AST_FUNCTION_H__

#include "ast.h"

void print_function_decl_ast(struct function_decl_ast *fn_decl);
void print_function_call_ast(struct function_call_ast *fn_call);

#endif
