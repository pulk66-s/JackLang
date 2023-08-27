#include "compiler/llvm/start.h"
#include "compiler/llvm/lib.h"

static LLVMModuleRef llvm_start()
{
    return create_default_llvm_module();
}

/**
 * @brief       Start the LLVM compiler with the given AST.
 * @param   ast The AST to compile.
*/
void cl_compiler_llvm_start(struct program_ast *ast)
{
    LLVMBuilderRef builder = LLVMCreateBuilder();
    LLVMModuleRef module = llvm_start();
    LLVMValueRef fn = create_empty_function(module, "main", LLVMInt32Type());
    LLVMBasicBlockRef block = create_empty_block(fn, "entry");

    LLVMPositionBuilderAtEnd(builder, block);
    output_llvm_module(module, "test.ll");
}
