#ifndef __CL_COMPILER_LLVM_CONTEXT_FUNCTIONS_H__
#define __CL_COMPILER_LLVM_CONTEXT_FUNCTIONS_H__

#include <llvm-c/Core.h>

struct function_context_llvm {
    const char *name;
    LLVMValueRef value;
    struct function_context_llvm *next;
};

/**
 * @brief           Store a function in the context.
 * @param   name    The name of the function.
 * @param   value   The value of the function.
 * @return          The function context.
*/
void llvm_function_context_store(const char *name, LLVMValueRef value);

/**
 * @brief           Get a function from the context.
 * @param   name    The name of the function.
 * @return          The function context.
*/
LLVMValueRef llvm_function_context_get(const char *name);

#endif