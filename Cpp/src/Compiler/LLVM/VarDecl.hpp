#ifndef __CL_COMPILER_LLVM_VARDECL_HPP__
#define __CL_COMPILER_LLVM_VARDECL_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include "Compiler/LLVM/Type.hpp"
#include <string>
#include <llvm/IR/Module.h>

namespace Comp::LLVM
{
    class VarDecl {
    public:
        VarDecl(std::string name, Type *t, Lib::Block *block, Lib::Value *value = nullptr);
        llvm::Value *get() { return this->varDecl->get(); };

    private:
        Lib::Alloca *varDecl = nullptr;
    };
} // namespace Comp::LLVM


#endif