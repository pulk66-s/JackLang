#include "compiler/llvm/lib/builder.h"

/**
 * @brief           Create a default builder for the given module.
 * @param   module  The module to create the builder for.
 * @return          The created builder.
 */
LLVMBuilderRef create_default_llvm_builder(LLVMModuleRef module)
{
    LLVMBuilderRef builder = LLVMCreateBuilder();

    LLVMPositionBuilderAtEnd(builder, LLVMGetLastBasicBlock(LLVMGetLastFunction(module)));
    return builder;
}
