#ifndef __CL_COMPILER_LLVM_CONDITION_H__
#define __CL_COMPILER_LLVM_CONDITION_H__

#include "ast.h"
#include <llvm-c/Core.h>

void llvm_from_condition(
    struct condition_ast *condition,
    LLVMModuleRef module,
    LLVMBuilderRef builder,
    LLVMBasicBlockRef parent_continue_block
);

#endif
