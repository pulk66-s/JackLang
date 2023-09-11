#ifndef __CL_AST_CONSTANT_HPP__
#define __CL_AST_CONSTANT_HPP__

#include "AST/ASTNamespace.hpp"
#include "AST/Expr.hpp"

namespace AST
{
    class Constant : public IExpr {
    public:
        Constant(int v): value(v) {};
        enum ast_type type() { return AST_CONSTANT; };
        int getValue() const { return value; };
    private:
        int value;
    };
} // namespace AST

#endif
