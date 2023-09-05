#ifndef __CL_COMPILER_LLVM_COMPARISON_H__
#define __CL_COMPILER_LLVM_COMPARISON_H__

#include "ast.h"
#include <llvm-c/Core.h>

LLVMValueRef llvm_from_comparison(struct comparison_ast *comparison, LLVMModuleRef module, LLVMBuilderRef builder);

#endif
