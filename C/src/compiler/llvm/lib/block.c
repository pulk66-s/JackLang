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
