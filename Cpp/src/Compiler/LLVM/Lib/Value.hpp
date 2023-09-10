#ifndef __CL_COMPILER_LLVM_LIB_VALUE_HPP__
#define __CL_COMPILER_LLVM_LIB_VALUE_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Constant.hpp"
#include <llvm/IR/Value.h>

namespace Comp::LLVM::Lib
{
    class Value {
    public:
        Value(Constant *constant);
        Value(llvm::Value *value);
        llvm::Value *get() { return this->value; };
    private:
        llvm::Value *value = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
