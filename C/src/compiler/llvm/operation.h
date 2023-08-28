#ifndef __CL_COMPILER_LLVM_OPERATION_H__
#define __CL_COMPILER_LLVM_OPERATION_H__

#include <llvm-c/Core.h>
#include "ast.h"

/**
 * @brief           Generate LLVM IR for a binary operation.
 * @param   op      The binary operation.
 * @param   module  The LLVM module.
 * @param   builder The LLVM IR builder.
*/
LLVMValueRef llvm_from_binary_operation(struct operation_ast *op, LLVMModuleRef module, LLVMBuilderRef builder);

#endif
