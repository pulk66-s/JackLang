#ifndef __CL_COMPILER_LLVM_LOOP_H__
#define __CL_COMPILER_LLVM_LOOP_H__

#include "ast.h"
#include <llvm-c/Core.h>

void llvm_from_loop(struct loop_ast *loop, LLVMModuleRef module, LLVMBuilderRef builder);

#endif