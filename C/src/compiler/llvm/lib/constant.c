#include "compiler/llvm/lib/constant.h"

/**
 * @brief           Create an Integer constant from value
 * @param   value   The value of the constant
 * @return          The constant
*/
LLVMValueRef create_int_constant(int value)
{
    return LLVMConstInt(LLVMInt32Type(), value, 0);
}
