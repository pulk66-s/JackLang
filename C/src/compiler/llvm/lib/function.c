#include "compiler/llvm/lib/function.h"
#include "compiler/llvm/lib/type.h"
#include "compiler/llvm/context.h"
#include "logger.h"
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

    printf("TEST\n");
    LLVMTypeRef function_type2 = LLVMTypeOf(function);
    printf("llvm type of function: is %s\n", LLVMPrintTypeToString(function_type2));
    LLVMPrintTypeToString(function_type2);
    LLVMGetElementType(function_type);
    printf("TEST PASSED\n");
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

/**
 * @brief           Get the last function of a module.
 * @param   module  The module.
 * @return          The last function.
*/
LLVMValueRef get_last_function(LLVMModuleRef module)
{
    return LLVMGetLastFunction(module);
}

/**
 * @brief           Create a LLVM function call from a name and arguments.
 * @param   module  The module to create the function in.
 * @param   builder The LLVM builder.
 * @param   name    The name of the function.
 * @param   args    The arguments of the function.
 * @return          The LLVM function.
*/
LLVMValueRef create_llvm_function_call(LLVMModuleRef module, LLVMBuilderRef builder , const char *name, LLVMValueRef *args)
{
    size_t s = 0;
    LLVMValueRef function = llvm_function_context_get(name);

    for (; args[s]; s++);
    logger().llvm("Function call has %ld args.\n", s);
    if (!function) {
        logger().llvm("Function %s not found.\n", name);
        return NULL;
    }
    if (!builder) {
        logger().llvm("Builder is null.\n");
        return NULL;
    }
    logger().llvm("Function %s found.\n", name);
    LLVMTypeRef f = LLVMTypeOf(function);
    if (!f) {
        logger().llvm("Function type is null.\n");
        return NULL;
    } else {
        logger().llvm("Function type is not null.\n");
    }
    LLVMTypeRef function_type = LLVMGetElementType(f);
    LLVMValueRef call = LLVMBuildCall2(builder, LLVMInt32Type(), function, args, 1, "");


    return call;
}
