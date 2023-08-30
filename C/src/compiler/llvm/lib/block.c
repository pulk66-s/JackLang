#include "compiler/llvm/lib/block.h"

/**
 * @brief               Create an empty block.
 * @param   function    The function to create the block in.
 * @param   name        The name of the block.
*/
LLVMBasicBlockRef create_empty_block(LLVMValueRef function, const char *name)
{
    return LLVMAppendBasicBlock(function, name);
}

/**
 * @brief           Push a block to the end of a builder
 * @param   builder The builder to push the block to.
 * @param   block   The block to push.
*/
void push_block_to_end(LLVMBuilderRef builder, LLVMBasicBlockRef block)
{
    LLVMPositionBuilderAtEnd(builder, block);
}
