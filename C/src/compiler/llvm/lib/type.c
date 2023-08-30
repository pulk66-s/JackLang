#include "compiler/llvm/lib/type.h"
#include <stdlib.h>

/**
 * @brief           Create the LLVM integer type.
 * @param   size    The size of the integer type.
 * @return          The LLVM integer type.
*/
LLVMTypeRef create_llvm_int_type(size_t size)
{
    switch (size) {
        case 8:
            return LLVMInt8Type();
        case 16:
            return LLVMInt16Type();
        case 32:
            return LLVMInt32Type();
        case 64:
            return LLVMInt64Type();
        default:
            return NULL;
    }
}
