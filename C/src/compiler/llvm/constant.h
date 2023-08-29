#ifndef __CL_COMPILER_LLVM_CONSTANT_H__
#define __CL_COMPILER_LLVM_CONSTANT_H__

#include <llvm-c/Core.h>
#include "ast.h"

/**
 * @brief               Create an llvm constant from an ast constant.
 * @param   constant    The ast constant.
 * @param   module      The llvm module.
 * @param   builder     The llvm builder.
 * @return              The llvm constant.
*/
LLVMValueRef llvm_from_constant(struct constant_ast *constant, LLVMModuleRef module, LLVMBuilderRef builder);

#endif
