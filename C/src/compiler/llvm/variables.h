#ifndef __CL_COMPILER_LLVM_VARIABLES_H__
#define __CL_COMPILER_LLVM_VARIABLES_H__

#include "ast.h"
#include <llvm-c/Core.h>

void llvm_from_var_decl(struct variable_decl_ast *decl, LLVMModuleRef module, LLVMBuilderRef builder);
LLVMValueRef llvm_from_var_call(struct variable_call_ast *call, LLVMModuleRef module, LLVMBuilderRef builder);
void llvm_from_var_redecl(struct variable_redecl_ast *redecl, LLVMModuleRef module, LLVMBuilderRef builder);

#endif
