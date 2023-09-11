#ifndef __CL_AST_NAMESPACE_HPP__
#define __CL_AST_NAMESPACE_HPP__

#include "CPT/CPTNamespace.hpp"

namespace AST
{
    class Program;
    class Block;
    class FunctionDecl;
    class VarDecl;
    class IExpr;
    class Constant;
    class Condition;

    class IType;
    namespace Type {
        class Int;
    };

    IExpr *createExpr(CPT::Packrat::IExpr *expr);
    IExpr *createValue(CPT::Packrat::IExpr *expr);

    enum ast_type {
        AST_UNKNOWN,
        AST_VARDECL,
        AST_COND,
        AST_CONSTANT
    };
} // namespace AST

#endif
