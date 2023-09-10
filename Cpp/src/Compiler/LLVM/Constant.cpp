#include "Compiler/LLVM/Constant.hpp"
#include <iostream>

namespace Comp::LLVM
{
    Constant::Constant(AST::Constant *constant, Lib::Context *ctx)
    {
        this->constant = new Lib::Constant(constant->getValue(), ctx);
    }
} // namespace Comp::LLVM
