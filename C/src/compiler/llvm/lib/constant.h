#ifndef __CL_COMPILER_LLVM_LIB_CONSTANT_H__
#define __CL_COMPILER_LLVM_LIB_CONSTANT_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create an Integer constant from value
 * @param   value   The value of the constant
 * @return          The constant
*/
LLVMValueRef create_int_constant(int value);

#endif