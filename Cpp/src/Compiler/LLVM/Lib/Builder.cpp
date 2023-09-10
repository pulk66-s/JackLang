#include <iostream>
#include "Compiler/LLVM/Lib/Builder.hpp"
#include "Compiler/LLVM/Lib/Type.hpp"
#include "Compiler/LLVM/Lib/Function.hpp"
#include "Compiler/LLVM/Lib/Block.hpp"
#include "Compiler/LLVM/Type.hpp"

namespace Comp::LLVM::Lib
{
    Builder::Builder(Context *context): context(context)
    {
        this->builder = new llvm::IRBuilder<>(*context->get());
    }

    void Builder::setInsertPoint(Lib::Block *block)
    {
        this->builder->SetInsertPoint(block->get());
    }

    void Builder::createIntRet(int value)
    {
        this->builder->CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*this->context->get()), value, true));
    }
} // namespace Comp::LLVM::Lib
