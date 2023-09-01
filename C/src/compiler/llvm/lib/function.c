#include "compiler/llvm/lib/function.h"
#include <stdlib.h>

/**
 * @brief               Create an empty function with default attributes.
 * @param   module      The module to create the function in.
 * @param   name        The name of the function.
 * @param   params      The parameters of the function.
 * @param   return_type The return type of the function.
*/
LLVMValueRef create_empty_function(LLVMModuleRef module, const char *name, LLVMTypeRef *params, LLVMTypeRef return_type)
{
    size_t s = 0;

    if (params) {
        for (; params[s]; s++);
    }

    LLVMTypeRef function_type = LLVMFunctionType(return_type, params, s, 0);
    LLVMValueRef function = LLVMAddFunction(module, name, function_type);

    return function;
}

/**
 * @brief               Get a parameter from a function.
 * @param   function    The function.
 * @param   index       The index of the parameter.
 * @return              The parameter.
*/
LLVMValueRef get_function_param(LLVMValueRef function, unsigned int index)
{
    return LLVMGetParam(function, index);
}
