#include "Compiler/LLVM/Lib/Block.hpp"
#include "Compiler/LLVM/VarDecl.hpp"
#include "Compiler/LLVM/Type.hpp"
#include <iostream>

namespace Comp::LLVM::Lib
{
    Block::Block(Context *context, Function *function)
    {
        if (!function)
        {
            std::cerr << "Function is null" << std::endl;
        }
        if (!function->get())
        {
            std::cerr << "Function is null" << std::endl;
        }
        if (!context->get())
        {
            std::cerr << "Context is null" << std::endl;
        }
        this->block = llvm::BasicBlock::Create(*context->get(), "entry", function->get());
    }

    Block::Block(Context *context, llvm::Function *function)
    {
        this->block = llvm::BasicBlock::Create(*context->get(), "entry", function);
    }

    Block::Block(Context *context, Function *function, std::string name)
    {
        this->block = llvm::BasicBlock::Create(*context->get(), name, function->get());
    }
} // namespace Comp::LLVM::Lib
