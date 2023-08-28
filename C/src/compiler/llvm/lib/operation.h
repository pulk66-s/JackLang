#ifndef __CL_COMPILER_LLVM_LIB_OPERATION_H__
#define __CL_COMPILER_LLVM_LIB_OPERATION_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create an operation from two operands and an operator
 * @param   op      The operator
 * @param   a       The first operand
 * @param   b       The second operand
 * @param   builder The builder
*/
LLVMValueRef create_llvm_operation(char op, LLVMValueRef a, LLVMValueRef b, LLVMBuilderRef builder);

#endif