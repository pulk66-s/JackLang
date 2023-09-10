#ifndef __CL_COMPILER_LLVM_LIB_MODULE_HPP__
#define __CL_COMPILER_LLVM_LIB_MODULE_HPP__

#include <llvm/IR/Module.h>
#include "Compiler/LLVM/Lib/Context.hpp"

namespace Comp::LLVM::Lib
{
    class Module {
    public:
        Module(Context *context);
        llvm::Module *get() { return module; };
        void dump();
        void dumpToFile(std::string filename);
    private:
        llvm::Module *module = nullptr;
    };
} // namespace Comp::LLVM::Lib


#endif