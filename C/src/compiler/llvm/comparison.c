#include "compiler/llvm/condition.h"
#include "compiler/llvm/expr.h"
#include "compiler/llvm/lib.h"

static LLVMIntPredicate create_operand(enum comparison_operand_ast operand)
{
    switch (operand) {
        case COMPARISON_OPERAND_EQUAL:
            return LLVMIntEQ;
        case COMPARISON_OPERAND_NOT_EQUAL:
            return LLVMIntNE;
        case COMPARISON_OPERAND_GREATER:
            return LLVMIntSGT;
        case COMPARISON_OPERAND_LESS:
            return LLVMIntSLT;
        case COMPARISON_OPERAND_GREATER_EQUAL:
            return LLVMIntSGE;
        case COMPARISON_OPERAND_LESS_EQUAL:
            return LLVMIntSLE;
        default:
            return LLVMIntEQ;
    }
}

LLVMValueRef llvm_from_comparison(struct comparison_ast *comparison, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMIntPredicate op;
    LLVMValueRef lhs, rhs;

    lhs = llvm_from_third_expr(comparison->left, module, builder);
    rhs = llvm_from_third_expr(comparison->right, module, builder);
    op = create_operand(comparison->operand);
    if (!lhs || !rhs) {
        return NULL;
    }
    return llvm_build_comparison(builder, op, lhs, rhs, "comparison");
}
