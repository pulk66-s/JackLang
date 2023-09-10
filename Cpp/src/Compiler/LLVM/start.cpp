#include "Compiler/CompilerNamespace.hpp"
#include "AST.hpp"
#include "Compiler/LLVM/Lib.hpp"
#include <llvm/IR/IRBuilder.h>

namespace Comp::LLVM
{
    void start(AST::Program *program) {
        Lib::Context context;
        Lib::Module module(&context);
        Lib::Builder builder(&context);

        for (AST::FunctionDecl *fn : program->getFunctions()) {
            Function f(fn, &context, &module, &builder);
            for (AST::Block *b : fn->getBlocks()) {
                f.addBlock(b);
            }
        }
        module.dump();
    }
} // namespace Comp::LLVM::Lib
