#include "Compiler/LLVM/Lib/Constant.hpp"

namespace Comp::LLVM::Lib
{
    Constant::Constant(llvm::Constant *constant)
    {
        this->constant = constant;
    }

    Constant::Constant(int value, Context *ctx)
    {
        this->constant = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*ctx->get()), value);
    }

    Type *Constant::getType() const
    {
        return new Type(this->constant->getType());
    }
} // namespace Comp::LLVM::Lib
