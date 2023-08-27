#include "compiler/llvm/lib/operation.h"
#include <stdlib.h>

/**
 * @brief           Create an operation from two operands and an operator
 * @param   op      The operator
 * @param   a       The first operand
 * @param   b       The second operand
 * @param   builder The builder
*/
LLVMValueRef create_operation(char op, LLVMValueRef a, LLVMValueRef b, LLVMBuilderRef builder)
{
    switch (op)
    {
        case '+':
            return LLVMBuildAdd(builder, a, b, "add");
        case '-':
            return LLVMBuildSub(builder, a, b, "sub");
        case '*':
            return LLVMBuildMul(builder, a, b, "mul");
        case '/':
            return LLVMBuildSDiv(builder, a, b, "div");
        case '%':
            return LLVMBuildSRem(builder, a, b, "rem");
        case '&':
            return LLVMBuildAnd(builder, a, b, "and");
        case '|':
            return LLVMBuildOr(builder, a, b, "or");
        case '^':
            return LLVMBuildXor(builder, a, b, "xor");
        case '<':
            return LLVMBuildICmp(builder, LLVMIntSLT, a, b, "lt");
        case '>':
            return LLVMBuildICmp(builder, LLVMIntSGT, a, b, "gt");
        case '=':
            return LLVMBuildICmp(builder, LLVMIntEQ, a, b, "eq");
        case '!':
            return LLVMBuildICmp(builder, LLVMIntNE, a, b, "ne");
        default:
            return NULL;
    }
}