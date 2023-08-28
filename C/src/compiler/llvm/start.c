#include "compiler/llvm/start.h"
#include "compiler/llvm/lib.h"
#include "compiler/llvm/line.h"
#include "logger.h"

static LLVMModuleRef llvm_start()
{
    return create_default_llvm_module();
}

static void llvm_from_ast(struct program_ast *ast, LLVMBuilderRef builder, LLVMModuleRef module)
{
    for (size_t i = 0; ast->lines[i]; i++) {
        logger().llvm("Compiling line %ld...\n", i);
        llvm_from_line(ast->lines[i], builder, module);
        logger().llvm("Line %ld compiled.\n", i);
    }
}

/**
 * @brief       Start the LLVM compiler with the given AST.
 * @param   ast The AST to compile.
*/
void cl_compiler_llvm_start(struct program_ast *ast)
{
    logger().llvm("Starting LLVM compiler...\n");

    LLVMBuilderRef builder = LLVMCreateBuilder();
    LLVMModuleRef module = llvm_start();
    LLVMValueRef fn = create_empty_function(module, "main", LLVMInt32Type());
    LLVMBasicBlockRef block = create_empty_block(fn, "entry");

    LLVMPositionBuilderAtEnd(builder, block);
    llvm_from_ast(ast, builder, module);
    output_llvm_module(module, "test.ll");
    logger().llvm("LLVM compiler finished.\n");
}
