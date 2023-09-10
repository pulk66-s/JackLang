#ifndef __CL_COMPILER_LLVM_VALUE_HPP__
#define __CL_COMPILER_LLVM_VALUE_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "AST.hpp"
#include "Compiler/LLVM/Constant.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include <llvm/IR/IRBuilder.h>

namespace Comp::LLVM
{
    class Value {
    public:
        Value(Lib::Value *value): value(value) {};
        Value(AST::IExpr *expr, Lib::Context *ctx);
        Lib::Value *get() { return this->value; };
    private:
        Lib::Value *value = nullptr;
    };
} // namespace Comp::LLVM

#endif
