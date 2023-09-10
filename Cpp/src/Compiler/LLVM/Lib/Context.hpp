#ifndef __CL_COMPILER_LLVM_LIB_CONTEXT_HPP__
#define __CL_COMPILER_LLVM_LIB_CONTEXT_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include <llvm/IR/Module.h>

namespace Comp::LLVM::Lib
{
    class Context {
    public:
        Context();
        llvm::LLVMContext *get() { return context; };
    private:
        llvm::LLVMContext *context = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
