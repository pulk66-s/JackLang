#include "compiler/llvm/lib/ret.h"

/**
 * @brief           Create a return instruction.
 * @param   value   The value to return.
 * @param   builder The builder.
*/
void create_llvm_ret(LLVMValueRef value, LLVMBuilderRef builder)
{
    LLVMBuildRet(builder, value);
}
