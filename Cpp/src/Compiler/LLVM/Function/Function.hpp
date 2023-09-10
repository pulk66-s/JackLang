#ifndef __CL_COMPILER_LLVM_Function_HPP__
#define __CL_COMPILER_LLVM_Function_HPP__

#include "Compiler/LLVM/Lib.hpp"
#include "Compiler/LLVM/Function/FunctionType.hpp"
#include "Compiler/LLVM/Block.hpp"
#include "Compiler/CompilerNamespace.hpp"
#include "AST.hpp"
#include <string>
#include <llvm/IR/Function.h>

namespace Comp::LLVM
{
    class Function {
    public:
        Function(Lib::Context *context, Lib::Module *mod, Lib::Builder *builder);
        Function(AST::FunctionDecl *fn, Lib::Context *context, Lib::Module *mod, Lib::Builder *builder);
        void addBlock(AST::Block *block);
    private:
        Lib::Builder *builder = nullptr;
        Lib::Function *function = nullptr;
        Lib::Context *ctx = nullptr;
    };
} // namespace Comp::LLVM

#endif
