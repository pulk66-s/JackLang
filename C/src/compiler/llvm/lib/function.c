#include "compiler/llvm/lib/function.h"
#include <stdlib.h>

/**
 * @brief               Create an empty function with default attributes.
 * @param   module      The module to create the function in.
 * @param   name        The name of the function.
 * @param   return_type The return type of the function.
*/
LLVMValueRef create_empty_function(LLVMModuleRef module, const char *name, LLVMTypeRef return_type)
{
    LLVMTypeRef *params = malloc(sizeof(LLVMTypeRef) * 1);
    params[0] = LLVMInt32Type();
    LLVMTypeRef function_type = LLVMFunctionType(return_type, params, 1, 0);
    LLVMValueRef function = LLVMAddFunction(module, name, function_type);

    return function;
}
