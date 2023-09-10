#ifndef __CL_COMPILER_LLVM_TYPE_HPP__
#define __CL_COMPILER_LLVM_TYPE_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include "AST.hpp"

namespace Comp::LLVM
{
    class Type {
    public:
        Type(AST::IType *type, Lib::Context *ctx);
        Lib::Type *get() { return this->type; };
    private:
        void createInt32(Lib::Context *ctx);
        Lib::Type *type = nullptr;
    };
} // namespace Comp::LLVM


#endif