#ifndef __CL_COMPILER_LLVM_CONDITION_HPP__
#define __CL_COMPILER_LLVM_CONDITION_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include "AST.hpp"

namespace Comp::LLVM
{
    class Condition {
    public:
        Condition(
            AST::Condition *cond,
            Lib::Context *context,
            Lib::Block *block,
            Lib::Function *function,
            Lib::Builder *builder
        );
    private:
        Lib::Condition *condition = nullptr;
    };
} // namespace Comp::LLVM

#endif
