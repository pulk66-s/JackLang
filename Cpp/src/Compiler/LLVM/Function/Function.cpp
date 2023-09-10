#include "Compiler/LLVM/Function/Function.hpp"
#include <iostream>

namespace Comp::LLVM
{
    Function::Function(Lib::Context *context, Lib::Module *mod, Lib::Builder *builder)
    : ctx(context), builder(builder)
    {
        this->function = new Lib::Function("main", new Lib::FunctionType(context), mod);
    }

    Function::Function(AST::FunctionDecl *fn, Lib::Context *context, Lib::Module *mod, Lib::Builder *builder)
    : ctx(context), builder(builder)
    {
        std::cout << "Creating function " << fn->getName() << std::endl;
        this->function = new Lib::Function(fn->getName(), new Lib::FunctionType(context), mod);
    }

    void Function::addBlock(AST::Block *block)
    {
        Block b(this->ctx, this->function, this->builder);

        this->builder->setInsertPoint(b.get());
        for (AST::IExpr *expr : block->getLines()) {
            b.addLine(expr);
        }
    }
} // namespace Comp::LLVM
