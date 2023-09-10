#ifndef __CL_COMPILER_LLVM_LIB_BUILDER_HPP__
#define __CL_COMPILER_LLVM_LIB_BUILDER_HPP__

#include <llvm/IR/IRBuilder.h>
#include "Compiler/LLVM/Lib/Context.hpp"
#include "Compiler/LLVM/Lib/Module.hpp"
#include "Compiler/LLVM/Lib/Builder.hpp"
#include "Compiler/CompilerNamespace.hpp"

namespace Comp::LLVM::Lib
{
    class Builder {
    public:
        Builder(Context *context);
        void createFunction(Lib::Module *mod);
        void setInsertPoint(Lib::Block *block);
        void createIntRet(int value);
        llvm::IRBuilder<> *get() const { return this->builder; }
    private:
        Context *context;
        llvm::IRBuilder<> *builder;
    };
} // namespace Comp::LLVM::Lib

#endif
