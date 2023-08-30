#ifndef __CL_COMPILER_LLVM_FUNCTION_H__
#define __CL_COMPILER_LLVM_FUNCTION_H__

#include "ast.h"
#include <llvm-c/Core.h>

/**
 * @brief           Create a LLVM function from a function declaration AST node.
 * @param   fn_decl The function declaration AST node.
 * @param   module  The module to create the function in.
 * @param   builder The LLVM builder.
*/
void create_llvm_function_from_ast(struct function_decl_ast *fn_decl, LLVMModuleRef module, LLVMBuilderRef builder);

#endif
