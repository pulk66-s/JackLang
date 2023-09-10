#include <iostream>
#include "Compiler/LLVM/Block.hpp"
#include "Compiler/LLVM/VarDecl.hpp"
#include "Compiler/LLVM/Value.hpp"

namespace Comp::LLVM
{
    Block::Block(Lib::Context *context, Lib::Function *function, Lib::Builder *builder)
    : builder(builder), ctx(context)
    {
        this->ctx = context;
        this->block = new Lib::Block(this->ctx, function);
    }

    void Block::generateVarDecl(AST::VarDecl *varDecl)
    {
        Value v(varDecl->getValue(), this->ctx);
        VarDecl(varDecl->getName(), new Type(varDecl->getType(), this->ctx), this->block, v.get());
    }

    void Block::addLine(AST::IExpr *expr)
    {
        switch (expr->type()) {
        case AST::AST_VARDECL:
            this->generateVarDecl(static_cast<AST::VarDecl *>(expr));
            break;
        default:
            std::cout << "Unknown expr type " << expr->type() << std::endl;
            break;
        }
    }
} // namespace Comp::LLVM
