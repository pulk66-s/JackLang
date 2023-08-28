#include "compiler/llvm/constant.h"
#include "logger.h"

/**
 * @brief               Create an llvm constant from an ast constant.
 * @param   constant    The ast constant.
 * @param   module      The llvm module.
 * @param   builder     The llvm builder.
 * @return              The llvm constant.
*/
LLVMValueRef llvm_from_constant(union constant_ast *constant, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting constant...\n");

    LLVMValueRef value = NULL;

    if (constant->int32) {
        logger().llvm("Constant is an int32.\n");
        value = LLVMConstInt(LLVMInt32Type(), constant->int32, 0);
        logger().llvm("Constant int32 finished.\n");
    }
    logger().llvm("Constant finished.\n");
    return value;
}
