#ifndef __CL_COMPILER_LLVM_LIB_FUNCTION_H__
#define __CL_COMPILER_LLVM_LIB_FUNCTION_H__

#include <llvm-c/Core.h>
#include <llvm-c/DataTypes.h>
#include <llvm-c/Target.h>
#include <llvm-c/ExecutionEngine.h>

/**
 * @brief               Create an empty function with default attributes.
 * @param   module      The module to create the function in.
 * @param   name        The name of the function.
 * @param   params      The parameters of the function.
 * @param   return_type The return type of the function.
*/
LLVMValueRef create_empty_function(LLVMModuleRef module, const char *name, LLVMTypeRef *params, LLVMTypeRef return_type);

/**
 * @brief               Get a parameter from a function.
 * @param   function    The function.
 * @param   index       The index of the parameter.
 * @return              The parameter.
*/
LLVMValueRef get_function_param(LLVMValueRef function, unsigned int index);

/**
 * @brief           Get the last function of a module.
 * @param   module  The module.
 * @return          The last function.
*/
LLVMValueRef get_last_function(LLVMModuleRef module);

/**
 * @brief           Create a LLVM function call from a name and arguments.
 * @param   module  The module to create the function in.
 * @param   builder The LLVM builder.
 * @param   name    The name of the function.
 * @param   args    The arguments of the function.
 * @return          The LLVM function.
*/
LLVMValueRef create_llvm_function_call(LLVMModuleRef module, LLVMBuilderRef builder , const char *name, LLVMValueRef *args);

#endif
