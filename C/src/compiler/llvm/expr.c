#include "compiler/llvm/expr.h"
#include "compiler/llvm/operation.h"
#include "compiler/llvm/ret.h"
#include "compiler/llvm/constant.h"
#include "logger.h"

/**
 * @brief           Create the LLVM IR from the primary expr
 * @param   expr    The primary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
*/
void llvm_from_primary_expr(union primary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting primary expr...\n");
    if (!expr) {
        logger().llvm("Primary expr is null.\n");
        return;
    }
    if (expr->ret) {
        logger().llvm("Primary expr is a ret.\n");
        llvm_from_ret(expr->ret, module, builder);
        logger().llvm("Primary expr ret finished.\n");
    }
    logger().llvm("Primary expr finished.\n");
}

/**
 * @brief           Create the LLVM IR from the secondary expr
 * @param   expr    The secondary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
 * @return          The LLVM value
*/
LLVMValueRef llvm_from_secondary_expr(union secondary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef value = NULL;
    logger().llvm("Starting secondary expr...\n");
    if (expr->operation) {
        logger().llvm("Secondary expr is an operation.\n");
        value = llvm_from_binary_operation(expr->operation, module, builder);
        logger().llvm("Secondary expr operation finished.\n");
    } else if (expr->constant) {
        logger().llvm("Secondary expr is a constant.\n");
        value = llvm_from_constant(expr->constant, module, builder);
        logger().llvm("Secondary expr constant finished.\n");
    }
    logger().llvm("Secondary expr finished.\n");
    return value;
}
