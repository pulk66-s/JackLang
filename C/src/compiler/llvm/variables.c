#include "compiler/llvm/variables.h"
#include "compiler/llvm/lib.h"
#include "compiler/llvm/expr.h"
#include "compiler/llvm/type.h"
#include "compiler/llvm/context.h"
#include "logger.h"

void llvm_from_var_decl(struct variable_decl_ast *decl, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef value, var;
    LLVMTypeRef type;

    logger().llvm("Starting var decl...\n");
    if (!decl) {
        logger().llvm("Var decl is null.\n");
        return;
    }
    value = llvm_from_third_expr(decl->expr, module, builder);
    if (!value) {
        logger().llvm("Var decl value is null.\n");
        return;
    }
    type = llvm_from_type(decl->type);
    if (!type) {
        logger().llvm("Var decl type is null.\n");
        return;
    }
    logger().llvm("Var decl type is not null.\n");
    var = llvm_variable(type, decl->name, builder);
    llvm_assign(var, value, builder);
}

LLVMValueRef llvm_from_var_call(struct variable_call_ast *call, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef var;

    logger().llvm("Starting var call...\n");
    if (!call) {
        logger().llvm("Var call is null.\n");
        return NULL;
    }
    var = llvm_get_variable(call->name, builder);
    logger().llvm("Var call finished.\n");
    return var;
}

void llvm_from_var_redecl(struct variable_redecl_ast *redecl, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef value, var;

    logger().llvm("Starting var redecl...\n");
    if (!redecl) {
        logger().llvm("Var redecl is null.\n");
        return;
    }
    value = llvm_from_third_expr(redecl->expr, module, builder);
    if (!value) {
        logger().llvm("Var redecl value is null.\n");
        return;
    }
    var = llvm_variable_context_get(redecl->name);
    llvm_reassign(var, value, redecl->operator, builder);
    logger().llvm("Var redecl finished.\n");
}
