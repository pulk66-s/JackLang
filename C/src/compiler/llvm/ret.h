#ifndef __CL_COMPILER_LLVM_RET_H__
#define __CL_COMPILER_LLVM_RET_H__

#include <llvm-c/Core.h>
#include "ast.h"

/**
 * @brief           Create the LLVM IR from the ret ast
 * @param  ret      The ret ast
 * @param  module   The LLVM module
 * @param  builder  The LLVM builder
*/
void llvm_from_ret(struct ret_ast *ret, LLVMModuleRef module, LLVMBuilderRef builder);

#endif