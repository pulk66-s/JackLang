#include "compiler/llvm/lib/comparison.h"

/**
 * @brief           Create a comparison instruction.
 * @param   builder The builder to build the instruction with.
 * @param   op      The comparison operator.
 * @param   lhs     The left-hand side of the comparison.
 * @param   rhs     The right-hand side of the comparison.
 * @param   name    The name of the instruction.
 * @return          The comparison instruction.
*/
LLVMValueRef llvm_build_comparison(LLVMBuilderRef builder, LLVMIntPredicate op, LLVMValueRef lhs, LLVMValueRef rhs, const char *name)
{
    return LLVMBuildICmp(builder, op, lhs, rhs, name);
}
