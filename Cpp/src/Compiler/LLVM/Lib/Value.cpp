#include "Compiler/LLVM/Lib/Value.hpp"

namespace Comp::LLVM::Lib
{
    Value::Value(Constant *constant)
    {
        this->value = constant->get();
    }

    Value::Value(llvm::Value *value)
    {
        this->value = value;
    }
} // namespace Comp::LLVM::Lib
