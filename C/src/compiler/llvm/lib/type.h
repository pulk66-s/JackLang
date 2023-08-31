#ifndef __CL_COMPILER_LLVM_LIB_TYPE_H__
#define __CL_COMPILER_LLVM_LIB_TYPE_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create the LLVM integer type.
 * @param   size    The size of the integer type.
 * @return          The LLVM integer type.
*/
LLVMTypeRef create_llvm_int_type(size_t size);

#endif