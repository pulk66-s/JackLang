#ifndef __CL_COMPILER_LLVM_LINE_H__
#define __CL_COMPILER_LLVM_LINE_H__

#include <llvm-c/Core.h>
#include "ast.h"

/**
 * @brief           Create the llvm code from an ast result
 * @param   line    The ast result
 * @param   builder The llvm builder
 * @param   module  The llvm module
*/
void llvm_from_line(struct line_ast *line, LLVMBuilderRef builder, LLVMModuleRef module);

#endif