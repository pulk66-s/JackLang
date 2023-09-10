#ifndef __CL_COMPILER_COMPILERNAMESPACE_HPP__
#define __CL_COMPILER_COMPILERNAMESPACE_HPP__

#include "AST.hpp"

namespace Comp
{
    namespace LLVM
    {
        class Function;
        class FunctionType;
        class Block;
        class VarDecl;
        class Type;
        class Block;
        class Value;
        class Constant;

        namespace Lib
        {
            class Module;
            class Builder;
            class Context;
            class Type;
            class Block;
            class Constant;
            class Value;
            class Alloca;
            class Function;
            class FunctionType;
        } // namespace Lib
        void start(AST::Program *program);
    } // namespace LLVM
} // namespace Comp

#endif
