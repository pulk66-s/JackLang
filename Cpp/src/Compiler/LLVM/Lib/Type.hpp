#ifndef __CL_COMPILER_LLVM_LIB_TYPE_HPP__
#define __CL_COMPILER_LLVM_LIB_TYPE_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Context.hpp"
#include <llvm/IR/Module.h>

namespace Comp::LLVM::Lib
{
    class Type {
    public:
        Type(llvm::Type *type): type(type) {};

        static llvm::Type *getVoidTy(Context *context) {
            return llvm::Type::getVoidTy(*context->get());
        }

        static llvm::Type *getIntTy(Context *context, unsigned int width) {
            return llvm::Type::getIntNTy(*context->get(), width);
        }

        llvm::Type *get() { return this->type; };
    private:
        llvm::Type *type = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
