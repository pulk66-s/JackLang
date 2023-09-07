#include "compiler/llvm/lib/variables.h"
#include "compiler/llvm/lib/type.h"
#include "compiler/llvm/context.h"
#include <string.h>

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
LLVMValueRef llvm_get_variable(const char *name, LLVMBuilderRef builder)
{
    return LLVMBuildLoad2(builder, create_llvm_int_type(32), llvm_variable_context_get(name), "");
}

/**
 * @brief               Reassign a variable with a new value depending on the operator
 * @param   var         The variable
 * @param   value       The value
 * @param   operator    The operator
 * @param   builder     The builder
*/
void llvm_reassign(LLVMValueRef var, LLVMValueRef value, char *operator, LLVMBuilderRef builder)
{
    if (strcmp(operator, "=") == 0) {
        llvm_assign(var, value, builder);
    } else if (strcmp(operator, "+=") == 0) {
        llvm_assign(var, LLVMBuildAdd(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "-=") == 0) {
        llvm_assign(var, LLVMBuildSub(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "*=") == 0) {
        llvm_assign(var, LLVMBuildMul(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "/=") == 0) {
        llvm_assign(var, LLVMBuildSDiv(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "%=") == 0) {
        llvm_assign(var, LLVMBuildSRem(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "<<=") == 0) {
        llvm_assign(var, LLVMBuildShl(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, ">>=") == 0) {
        llvm_assign(var, LLVMBuildLShr(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "&=") == 0) {
        llvm_assign(var, LLVMBuildAnd(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "^=") == 0) {
        llvm_assign(var, LLVMBuildXor(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    } else if (strcmp(operator, "|=") == 0) {
        llvm_assign(var, LLVMBuildOr(builder, llvm_get_variable(LLVMGetValueName(var), builder), value, ""), builder);
    }
}
