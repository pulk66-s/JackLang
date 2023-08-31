#include "compiler/llvm/lib/variables.h"
#include "compiler/llvm/lib/type.h"
#include "compiler/llvm/context.h"

/**
 * @brief           Create a new variable from the type ref
 * @param   type    The type ref
 * @param   name    The name of the variable
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_variable(LLVMTypeRef type, const char *name, LLVMBuilderRef builder)
{
    LLVMValueRef var = LLVMBuildAlloca(builder, type, name);

    llvm_variable_context_store(name, var);
    return var;
}

/**
 * @brief           Assign a value to a variable
 * @param   var     The variable
 * @param   value   The value
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_assign(LLVMValueRef var, LLVMValueRef value, LLVMBuilderRef builder)
{
    return LLVMBuildStore(builder, value, var);
}

/**
 * @brief           Get the variable content
 * @param   name    The variable name
 * @param   builder The builder
 * @return          The variable ref
*/
LLVMValueRef llvm_get_variable(char *name, LLVMBuilderRef builder)
{
    return LLVMBuildLoad2(builder, create_llvm_int_type(32), llvm_variable_context_get(name), "");
}