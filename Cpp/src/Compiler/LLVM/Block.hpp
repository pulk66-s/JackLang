#ifndef __CL_COMPILER_LLVM_BLOCK_HPP__
#define __CL_COMPILER_LLVM_BLOCK_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include "AST.hpp"

namespace Comp::LLVM
{
    class Block {
    public:
        Block(Lib::Context *context, Lib::Function *function, Lib::Builder *builder);
        Block(AST::Block *block, Lib::Context *context, Lib::Function *function, Lib::Builder *builder);
        void addLine(AST::IExpr *expr);
        Lib::Block *get() const { return this->block; }
    private:
        void generateVarDecl(AST::VarDecl *varDecl);
        void generateCond(AST::Condition *cond);
        Lib::Builder *builder = nullptr;
        Lib::Context *ctx = nullptr;
        Lib::Block *block = nullptr;
        Lib::Function *function = nullptr;
    };
} // namespace Comp::LLVM

#endif
