#ifndef __CL_COMPILER_LLVM_LIB_FUNCTIONTYPE_HPP__
#define __CL_COMPILER_LLVM_LIB_FUNCTIONTYPE_HPP__

#include "Compiler/LLVM/Lib/FunctionType.hpp"
#include "Compiler/LLVM/Lib/Context.hpp"
#include "Compiler/LLVM/Lib/Type.hpp"
#include <llvm/IR/Module.h>

namespace Comp::LLVM::Lib
{
    class FunctionType {
    public:
        FunctionType(Context *context);
        FunctionType(llvm::Type *returnType, std::vector<llvm::Type *> params = {}, bool isVarArg = false);
        llvm::FunctionType *get() { return functionType; };
    private:
        llvm::FunctionType *functionType = nullptr;
    };
} // namespace Comp::LLVM::Lib

#endif
