#ifndef __CL_AST_VARDECL_HPP__
#define __CL_AST_VARDECL_HPP__

#include "AST/Expr.hpp"
#include "AST/ASTNamespace.hpp"
#include "AST/Type.hpp"
#include "CPT.hpp"
#include <string>

namespace AST
{
    class VarDecl : public IExpr {
    public:
        VarDecl(CPT::Grammar::VariableDecl *vardecl);
        enum ast_type type() { return AST_VARDECL; };
        std::string getName() const { return name; };
        IType *getType() const { return t; };
        IExpr *getValue() const { return value; };
    private:
        std::string name = "";
        IType *t = nullptr;
        IExpr *value = nullptr;
    };
} // namespace AST

#endif
