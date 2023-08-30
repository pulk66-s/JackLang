#include "compiler/llvm/type.h"
#include "compiler/llvm/lib.h"

/**
 * @brief       Create the LLVM type for the given AST type.
 * @param type  The AST type.
 * @return      The LLVM type.
*/
LLVMTypeRef llvm_from_type(enum type_ast type)
{
    switch (type) {
        case INT_TYPE_AST:
            return create_llvm_int_type(32);
        default:
            return NULL;
    }
}
