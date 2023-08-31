#include "compiler/llvm/expr.h"
#include "compiler/llvm/operation.h"
#include "compiler/llvm/ret.h"
#include "compiler/llvm/function.h"
#include "compiler/llvm/constant.h"
#include "compiler/llvm/variables.h"
#include "logger.h"

/**
 * @brief           Create the LLVM IR from the primary expr
 * @param   expr    The primary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
*/
void llvm_from_primary_expr(struct primary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting primary expr...\n");
    if (!expr) {
        logger().llvm("Primary expr is null.\n");
        return;
    }
    switch (expr->type) {
        case AST_PRIMARY_EXPR_FUNCTION_DECL:
            logger().llvm("Primary expr is a func decl.\n");
            create_llvm_function_from_ast(expr->u.fn_decl, module, builder);
            logger().llvm("Primary expr func decl finished.\n");
            break;
        default:
            logger().llvm("Primary expr is unknown. %d\n", expr->type);
            break;
    }
}

/**
 * @brief           Create the LLVM IR from the secondary expr
 * @param   expr    The secondary ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
 * @return          The LLVM value
*/
void llvm_from_secondary_expr(struct secondary_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder)
{
    logger().llvm("Starting secondary expr...\n");
    if (!expr) {
        logger().llvm("Secondary expr is null.\n");
        return;
    }
    switch (expr->type) {
        case AST_SECONDARY_EXPR_RET:
            logger().llvm("Secondary expr is a ret.\n");
            llvm_from_ret(expr->u.ret, module, builder);
            logger().llvm("Secondary expr ret finished.\n");
            break;
        case AST_SECONDARY_VAR_DECL:
            logger().llvm("Secondary expr is a var decl.\n");
            llvm_from_var_decl(expr->u.var_decl, module, builder);
            logger().llvm("Secondary expr var decl finished.\n");
            break;
        default:
            logger().llvm("Secondary expr is unknown. %d\n", expr->type);
            break;
    }
    logger().llvm("Secondary expr finished.\n");
}

/**
 * @brief           Create the LLVM IR from the third expr
 * @param   expr    The third ast expr
 * @param   module  The LLVM module
 * @param   builder The LLVM builder
 * @return          The LLVM value
*/
LLVMValueRef llvm_from_third_expr(struct third_expr_ast *expr, LLVMModuleRef module, LLVMBuilderRef builder)
{
    LLVMValueRef value = NULL;
    logger().llvm("Starting third expr...\n");
    switch (expr->type) {
        case AST_THIRD_EXPR_OPERATION:
            logger().llvm("Third expr is an operation.\n");
            value = llvm_from_binary_operation(expr->u.operation, module, builder);
            logger().llvm("Third expr operation finished.\n");
            break;
        case AST_THIRD_EXPR_CONSTANT:    
            logger().llvm("Third expr is a constant.\n");
            value = llvm_from_constant(expr->u.constant, module, builder);
            logger().llvm("Third expr constant finished.\n");
            break;
        case AST_THIRD_EXPR_VAR_CALL:
            logger().llvm("Third expr is a var call.\n");
            value = llvm_from_var_call(expr->u.var_call, module, builder);
            logger().llvm("Third expr var call finished.\n");
            break;
        default:
            logger().llvm("third expr is unknown. %d\n", expr->type);
            break;
    }
    logger().llvm("Third expr finished.\n");
    return value;
}
