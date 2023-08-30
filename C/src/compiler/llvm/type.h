#ifndef __CL_COMPILER_LLVM_TYPE_H__
#define __CL_COMPILER_LLVM_TYPE_H__

#include "ast.h"
#include <llvm-c/Core.h>

/**
 * @brief       Create the LLVM type for the given AST type.
 * @param type  The AST type.
 * @return      The LLVM type.
*/
LLVMTypeRef llvm_from_type(enum type_ast type);

#endif