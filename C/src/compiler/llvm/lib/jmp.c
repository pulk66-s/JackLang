#include "compiler/llvm/lib/jmp.h"

/**
 * @brief           Create a jump to a block.
 * @param   builder The builder to create the jump in.
 * @param   block   The block to jump to.
 * @return          The jump instruction.
*/
LLVMValueRef llvm_jmp(LLVMBuilderRef builder, LLVMBasicBlockRef block)
{
    return LLVMBuildBr(builder, block);
}

/**
 * @brief           Create a conditional jump to a block.
 * @param   builder The builder to create the jump in.
 * @param   cond    The condition to check.
 * @param   block   The block to jump to if the condition is true.
 * @param   else_   The block to jump to if the condition is false.
 * @return          The jump instruction.
*/
LLVMValueRef llvm_jmp_if(LLVMBuilderRef builder, LLVMValueRef cond, LLVMBasicBlockRef block, LLVMBasicBlockRef else_)
{
    return LLVMBuildCondBr(builder, cond, block, else_);
}
