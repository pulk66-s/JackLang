#ifndef __CL_COMPILER_LLVM_LIB_CONSTANT_HPP__
#define __CL_COMPILER_LLVM_LIB_CONSTANT_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Context.hpp"
#include "Compiler/LLVM/Lib/Type.hpp"
#include <llvm/IR/IRBuilder.h>

namespace Comp::LLVM::Lib
{
    class Constant {
    public:
        Constant(llvm::Constant *constant);
        Constant(int value, Context *ctx);
        Type *getType() const;
        llvm::Constant *get() { return this->constant; };
    private:
        llvm::Constant *constant = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
