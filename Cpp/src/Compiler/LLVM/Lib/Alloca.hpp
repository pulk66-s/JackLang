#ifndef __CL_COMPILIER_LLVM_LIB_ALLOCA_HPP__
#define __CL_COMPILIER_LLVM_LIB_ALLOCA_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Type.hpp"
#include "Compiler/LLVM/Lib/Block.hpp"
#include <string>
#include <llvm/IR/Instructions.h>

namespace Comp::LLVM::Lib
{
    class Alloca {
    public:
        Alloca(std::string name, Type *type, Block *block);
        llvm::Value *get() { return this->alloca; };
    private:
        llvm::AllocaInst *alloca = nullptr;
    };
} // namespace Comp::LLVM::Lib


#endif