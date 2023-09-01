#include "compiler/llvm/function.h"
#include "compiler/llvm/type.h"
#include "compiler/llvm/lib.h"
#include "compiler/llvm/expr.h"
#include "logger.h"

/**
 * @brief           Create a LLVM function from a function declaration AST node.
 * @param   fn_decl The function declaration AST node.
 * @param   module  The module to create the function in.
 * @param   builder The LLVM builder.
*/
void create_llvm_function_from_ast(struct function_decl_ast *fn_decl, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting function decl...\n");

    char *name = fn_decl->name;
    LLVMTypeRef ret_type = llvm_from_type(fn_decl->type);
    LLVMTypeRef *params;
    LLVMValueRef function;
    size_t size = 0;

    for (; fn_decl->args[size]; size++);
    params = malloc(sizeof(LLVMTypeRef) * (size + 1));
    params[size] = NULL;
    logger().llvm("Function decl has %ld args.\n", size);
    for (size_t i = 0; fn_decl->args[i]; i++) {
        params[i] = llvm_from_type(fn_decl->args[i]->type);
    }
    function = create_empty_function(module, name, params, ret_type);
    push_block_to_end(builder, create_empty_block(function, "entry"));
    for (size_t i = 0; fn_decl->args[i]; i++) {
        LLVMValueRef param_var = llvm_variable(llvm_from_type(fn_decl->args[i]->type), fn_decl->args[i]->name, builder);
        LLVMValueRef arg = get_function_param(function, i);

        llvm_assign(param_var, arg, builder);
    }
    logger().llvm("Function decl lines.\n");
    for (size_t i = 0; fn_decl->lines[i]; i++) {
        llvm_from_secondary_expr(fn_decl->lines[i], module, builder);
    }
    logger().llvm("Function decl finished.\n");
}
