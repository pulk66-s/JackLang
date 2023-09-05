#include "compiler/llvm/loop.h"
#include "compiler/llvm/expr.h"
#include "compiler/llvm/lib.h"
#include "logger.h"

void llvm_from_loop(struct loop_ast *loop, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef cond;
    LLVMBasicBlockRef loop_block, continue_block, condition_block;

    logger().llvm("Starting loop...\n");
    if (!loop) {
        logger().llvm("Loop is null.\n");
        return;
    }
    continue_block = create_empty_block(get_last_function(module), "loop_continue");
    condition_block = create_empty_block(get_last_function(module), "loop_condition");
    loop_block = create_empty_block(get_last_function(module), "loop");
    if (loop->init) {
        logger().llvm("Loop has an init.\n");
        llvm_from_third_expr(loop->init, module, builder);
    } else {
        logger().llvm("Loop has no init.\n");
    }
    llvm_jmp(builder, condition_block);
    logger().llvm("Loop has a condition.\n");
    push_block_to_end(builder, condition_block);
    cond = llvm_from_third_expr(loop->condition, module, builder);
    llvm_jmp_if(builder, cond, loop_block, continue_block);
    logger().llvm("Loop has a body.\n");
    push_block_to_end(builder, loop_block);
    for (size_t i = 0; loop->body[i]; i++) {
        llvm_from_secondary_expr(loop->body[i], module, builder);
    }
    if (loop->increment) {
        logger().llvm("Loop has an increment.\n");
        llvm_from_third_expr(loop->increment, module, builder);
    } else {
        logger().llvm("Loop has no increment.\n");
    }
    llvm_jmp(builder, condition_block);
    push_block_to_end(builder, continue_block);
    logger().llvm("Ending loop...\n");
}
