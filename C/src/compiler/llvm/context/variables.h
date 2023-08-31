#ifndef __CL_COMPILER_LLVM_CONTEXT_VARIABLES_H__
#define __CL_COMPILER_LLVM_CONTEXT_VARIABLES_H__

#include <llvm-c/Core.h>

struct variable_context_llvm {
    char *name;
    LLVMValueRef value;
    struct variable_context_llvm *next;
};

/**
 * @brief           Store a variable in the context.
 * @param   name    The name of the variable.
 * @param   value   The value of the variable.
 * @return          The variable context.
*/
void llvm_variable_context_store(char *name, LLVMValueRef value);

/**
 * @brief           Get a variable from the context.
 * @param   name    The name of the variable.
 * @return          The variable context.
*/
LLVMValueRef llvm_variable_context_get(char *name);

#endif