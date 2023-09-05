#include "compiler/llvm/condition.h"
#include "compiler/llvm/expr.h"
#include "compiler/llvm/lib.h"
#include "logger.h"

void llvm_from_condition(
    struct condition_ast *condition,
    LLVMModuleRef module,
    LLVMBuilderRef builder
) {
    LLVMValueRef cond;
    LLVMBasicBlockRef then_block, else_block, continue_block;
    bool then_terminator = false, else_terminator = false;

    logger().llvm("Starting condition...\n");
    if (!condition) {
        logger().llvm("Condition is null.\n");
        return;
    }
    cond = llvm_from_third_expr(condition->cond, module, builder);
    then_block = create_empty_block(get_last_function(module), "then");
    continue_block = create_empty_block(get_last_function(module), "continue");
    else_block = condition->else_ ? create_empty_block(get_last_function(module), "else") : continue_block;
    llvm_jmp_if(builder, cond, then_block, else_block);
    push_block_to_end(builder, then_block);
    for (size_t i = 0; condition->then[i]; i++) {
        if (condition->then[i]->type == AST_SECONDARY_EXPR_COND) {
            llvm_from_condition(condition->then[i]->u.condition, module, builder);
        } else {
            llvm_from_secondary_expr(condition->then[i], module, builder);
        }
    }
    then_terminator = is_last_action_terminator(builder);
    if (!then_terminator) {
        logger().llvm("Adding jump from then block to continue block.\n");
        llvm_jmp(builder, continue_block);
    }
    if (condition->else_) {
        push_block_to_end(builder, else_block);
        for (size_t i = 0; condition->else_[i]; i++) {
            if (condition->else_[i]->type == AST_SECONDARY_EXPR_COND) {
                llvm_from_condition(condition->else_[i]->u.condition, module, builder);
            } else {
                llvm_from_secondary_expr(condition->else_[i], module, builder);
            }
        }
    }
    else_terminator = is_last_action_terminator(builder);
    if (!else_terminator) {
        logger().llvm("Adding jump from else block to continue block.\n");
        llvm_jmp(builder, continue_block);
    }
    push_block_to_end(builder, continue_block);
}
