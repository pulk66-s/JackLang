#include "compiler/llvm/operation.h"
#include "compiler/llvm/lib.h"
#include "compiler/llvm/expr.h"
#include "logger.h"

/**
 * @brief           Generate LLVM IR for a binary operation.
 * @param   op      The binary operation.
 * @param   module  The LLVM module.
 * @param   builder The LLVM IR builder.
*/
LLVMValueRef llvm_from_binary_operation(struct operation_ast *op, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting binary operation...\n");
    logger().llvm("Starting left third expr...\n");

    LLVMValueRef left = llvm_from_third_expr(op->left, module, builder);

    logger().llvm("Left third expr finished.\n");
    logger().llvm("Starting right third expr...\n");

    LLVMValueRef right = llvm_from_third_expr(op->right, module, builder);

    logger().llvm("Right third expr finished.\n");
 
    LLVMValueRef res = create_llvm_operation(op->operand, left, right, builder);

    logger().llvm("Binary operation finished.\n");
    return res;
}
