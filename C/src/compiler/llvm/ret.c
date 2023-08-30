#include "compiler/llvm/ret.h"
#include "compiler/llvm/expr.h"
#include "compiler/llvm/lib.h"
#include "logger.h"

/**
 * @brief           Create the LLVM IR from the ret ast
 * @param  ret      The ret ast
 * @param  module   The LLVM module
 * @param  builder  The LLVM builder
*/
void llvm_from_ret(struct ret_ast *ret, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting ret...\n");
    logger().llvm("Starting Third expr.\n");

    LLVMValueRef expr = llvm_from_third_expr(ret->expr, module, builder);

    logger().llvm("Third expr finished.\n");
    create_llvm_ret(expr, builder);
    logger().llvm("Ret finished.\n");
}
