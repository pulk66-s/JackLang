#ifndef __CL_COMPILER_LLVM_FUNCTION_FUNCTIONTYPE_HPP__
#define __CL_COMPILER_LLVM_FUNCTION_FUNCTIONTYPE_HPP__

#include "Compiler/CompilerNamespace.hpp"
#include <llvm/IR/Function.h>

namespace Comp::LLVM
{
    class FunctionType {
    public:
        FunctionType();
        FunctionType(llvm::Type *returnType, std::vector<llvm::Type *> params = {}, bool isVarArg = false);
        llvm::FunctionType *get() { return functionType; };
    private:
        llvm::FunctionType *functionType = nullptr;
    };
} // namespace Comp::LLVM


#endif
