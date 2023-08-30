#ifndef __CL_COMPILER_LLVM_EXPR_H__
#define __CL_COMPILER_LLVM_EXPR_H__

#include <llvm-c/Core.h>
#include "ast.h"

/**
 * @brief           Create the LLVM IR from the primary expr
 * @param   expr    The primary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
*/
void llvm_from_primary_expr(struct primary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder);

/**
 * @brief           Create the LLVM IR from the secondary expr
 * @param   expr    The secondary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
 * @return          The LLVM value
*/
void llvm_from_secondary_expr(struct secondary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder);

/**
 * @brief           Create the LLVM IR from the third expr
 * @param   expr    The third ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
 * @return          The LLVM value
*/
LLVMValueRef llvm_from_third_expr(struct third_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder);

#endif