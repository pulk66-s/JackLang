#ifndef __CL_COMPILER_LLVM_LIB_RET_H__
#define __CL_COMPILER_LLVM_LIB_RET_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create a return instruction.
 * @param   value   The value to return.
 * @param   builder The builder.
*/
void create_llvm_ret(LLVMValueRef value, LLVMBuilderRef builder);

#endif