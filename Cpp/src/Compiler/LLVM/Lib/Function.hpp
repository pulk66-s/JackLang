#ifndef __CL_COMPILER_LLVM_LIB_FUNCTION_HPP__
#define __CL_COMPILER_LLVM_LIB_FUNCTION_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include "Compiler/LLVM/Lib/FunctionType.hpp"
#include "Compiler/LLVM/Lib/Module.hpp"
#include <llvm/IR/Function.h>
#include <string>

namespace Comp::LLVM::Lib
{
    class Function {
    public:
        Function(std::string name, FunctionType *t, Module *mod);
        llvm::Function *get() { return this->function; };
    private:
        FunctionType *functionType = nullptr;
        llvm::Function *function = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
