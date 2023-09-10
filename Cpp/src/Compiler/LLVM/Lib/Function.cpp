#include "Compiler/LLVM/Lib/Function.hpp"

namespace Comp::LLVM::Lib
{
    Function::Function(std::string name, FunctionType *t, Module *mod)
    {
        this->functionType = t;
        this->function = llvm::Function::Create(t->get(), llvm::Function::ExternalLinkage, name, mod->get());
    }
} // namespace Comp::LLVM::Lib
