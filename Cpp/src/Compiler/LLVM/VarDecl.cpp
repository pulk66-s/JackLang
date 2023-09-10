#include "Compiler/LLVM/VarDecl.hpp"

namespace Comp::LLVM
{
    VarDecl::VarDecl(std::string name, Type *t, Lib::Block *block, Lib::Value *value)
    {
        this->varDecl = new Lib::Alloca(name, t->get(), block);
        if (value != nullptr) {
            new llvm::StoreInst(value->get(), this->varDecl->get(), false, block->get());
        }
    }
} // namespace Comp::LLVM
