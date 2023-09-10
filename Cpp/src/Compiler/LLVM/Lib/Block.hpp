#ifndef __CL_COMPILER_LLVM_LIB_BLOCK_HPP__
#define __CL_COMPILER_LLVM_LIB_BLOCK_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/Context.hpp"
#include "Compiler/LLVM/Function.hpp"
#include <llvm/IR/BasicBlock.h>

namespace Comp::LLVM::Lib
{
    class Block {
    public:
        Block(Context *context, Function *function);
        Block(Context *context, llvm::Function *function);
        Block(Context *context, Function *function, std::string name);
        llvm::BasicBlock *get() const { return this->block; }
    private:
        llvm::BasicBlock *block;
    };
} // namespace Comp::LLVM::Lib

#endif
