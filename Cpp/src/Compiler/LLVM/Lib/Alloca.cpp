#include "Compiler/LLVM/Lib/Alloca.hpp"
#include <iostream>

namespace Comp::LLVM::Lib
{
    Alloca::Alloca(std::string name, Type *type, Block *block)
    {
        this->alloca = new llvm::AllocaInst(type->get(), 0, name, block->get());
    }
} // namespace Comp::LLVM::Lib
