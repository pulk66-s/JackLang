#ifndef __CL_AST_EXPR_HPP__
#define __CL_AST_EXPR_HPP__

#include "AST/ASTNamespace.hpp"

namespace AST
{
    class IExpr {
    public:
        virtual ~IExpr() = default;
        virtual enum ast_type type() = 0;
    };
} // namespace AST


#endif