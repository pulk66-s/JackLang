#ifndef __CL_COMPILER_LLVM_START_H__
#define __CL_COMPILER_LLVM_START_H__

#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include "ast.h"

/**
 * @brief       Start the LLVM compiler with the given AST.
 * @param   ast The AST to compile.
*/
void cl_compiler_llvm_start(struct program_ast *ast);

#endif