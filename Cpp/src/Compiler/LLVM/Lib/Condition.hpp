#ifndef __CL_COMPILER_LLVM_LIB_CONDITION_HPP__
#define __CL_COMPILER_LLVM_LIB_CONDITION_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Block.hpp"
#include "Compiler/LLVM/Lib/Value.hpp"
#include <llvm/IR/IRBuilder.h>

namespace Comp::LLVM::Lib
{
    class Condition {
    public:
        Condition(
            Block *true_,
            Block *false_,
            Value *condition,
            Block *source,
            Builder *builder
        );
        llvm::Value *getCond() const { return this->condition; };
        Block *getTrue() const { return this->true_; };
        Block *getFalse() const { return this->false_; };
    private:
        llvm::Value *condition = nullptr;
        Block *true_ = nullptr;
        Block *false_ = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
