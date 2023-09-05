#include "compiler/llvm/lib/condition.h"

/**
 * @brief               Create a jump instruction if the condition is true.
 * @param   builder     The builder to use.
 * @param   condition   The condition to check.
 * @param   true_block  The block to jump to if the condition is true.
 * @param   false_block The block to jump to if the condition is false.
 * @return  The created instruction.
*/
LLVMValueRef llvm_build_cond(LLVMBuilderRef builder, LLVMValueRef condition, LLVMBasicBlockRef true_block, LLVMBasicBlockRef false_block)
{
    return LLVMBuildCondBr(builder, condition, true_block, false_block);
}
