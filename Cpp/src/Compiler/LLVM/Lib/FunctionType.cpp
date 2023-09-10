#include "Compiler/LLVM/Lib/FunctionType.hpp"

namespace Comp::LLVM::Lib
{
    FunctionType::FunctionType(Context *context)
    {
        this->functionType = llvm::FunctionType::get(Type::getVoidTy(context), {}, false);
    }

    FunctionType::FunctionType(llvm::Type *returnType, std::vector<llvm::Type *> params, bool isVarArg)
    {
        this->functionType = llvm::FunctionType::get(returnType, params, isVarArg);
    }
} // namespace Comp::LLVM::Lib
