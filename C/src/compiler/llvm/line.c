#include "compiler/llvm/line.h"
#include "compiler/llvm/expr.h"
#include "logger.h"

/**
 * @brief           Create the llvm code from an ast result
 * @param   line    The ast result
 * @param   builder The llvm builder
 * @param   module  The llvm module
*/
void llvm_from_line(struct line_ast *line, LLVMBuilderRef builder, LLVMModuleRef module)
{
    logger().llvm("Starting line...\n");
    llvm_from_primary_expr(line->expr, module, builder);
    logger().llvm("Line finished.\n");
}
