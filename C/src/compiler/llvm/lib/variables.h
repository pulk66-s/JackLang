#ifndef __CL_COMPILER_LLVM_LIB_VARIABLES_H__
#define __CL_COMPILER_LLVM_LIB_VARIABLES_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create a new variable from the type ref
 * @param   type    The type ref
 * @param   name    The name of the variable
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_variable(LLVMTypeRef type, const char *name, LLVMBuilderRef builder);

/**
 * @brief           Assign a value to a variable
 * @param   var     The variable
 * @param   value   The value
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_assign(LLVMValueRef var, LLVMValueRef value, LLVMBuilderRef builder);

/**
 * @brief           Get the variable content
 * @param   name    The variable name
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_get_variable(char *var, LLVMBuilderRef builder);

/**
 * @brief               Reassign a variable with a new value depending on the operator
 * @param   var         The variable
 * @param   value       The value
 * @param   operator    The operator
 * @param   builder     The builder
*/
void llvm_reassign(LLVMValueRef var, LLVMValueRef value, char *operator, LLVMBuilderRef builder);

#endif