#ifndef __CL_COMPILER_LLVM_LIB_FUNCTION_H__
#define __CL_COMPILER_LLVM_LIB_FUNCTION_H__

#include <llvm-c/Core.h>

/**
 * @brief               Create an empty function with default attributes.
 * @param   module      The module to create the function in.
 * @param   name        The name of the function.
 * @param   params      The parameters of the function.
 * @param   return_type The return type of the function.
*/
LLVMValueRef create_empty_function(LLVMModuleRef module, const char *name, LLVMTypeRef *params, LLVMTypeRef return_type);

#endif
