#include "Compiler/LLVM/Lib/Context.hpp"

namespace Comp::LLVM::Lib
{
    Context::Context()
    {
        this->context = new llvm::LLVMContext();
    }
} // namespace Comp::LLVM::Lib
