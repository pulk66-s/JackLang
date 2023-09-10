#ifndef __CL_COMPILER_LLVM_CONSTANT_HPP__
#define __CL_COMPILER_LLVM_CONSTANT_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include "AST.hpp"

namespace Comp::LLVM
{
    class Constant {
    public:
        Constant(AST::Constant *constant, Lib::Context *ctx);
        Lib::Constant *get() { return this->constant; };

    private:
        Lib::Constant *constant = nullptr;
    };
} // namespace Comp::LLVM


#endif
