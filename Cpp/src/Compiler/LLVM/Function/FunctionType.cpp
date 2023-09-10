#include "Compiler/LLVM/Function/FunctionType.hpp"

namespace Comp::LLVM
{
    FunctionType::FunctionType()
    {
    }

    FunctionType::FunctionType(llvm::Type *returnType, std::vector<llvm::Type *> params, bool isVarArg)
    {
        this->functionType = llvm::FunctionType::get(returnType, params, isVarArg);
    }
} // namespace Comp::LLVM
