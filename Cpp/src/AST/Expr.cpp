#include "AST/Expr.hpp"
#include "AST/VarDecl.hpp"
#include "AST/Constant.hpp"
#include "AST/Condition.hpp"
#include "CPT.hpp"

namespace AST
{
    IExpr *createExpr(CPT::Packrat::IExpr *expr)
    {
        switch (expr->type()) {
        case CPT::CPT_VARDECL:
            return new VarDecl((CPT::Grammar::VariableDecl *)expr);
        case CPT::CPT_COND:
            return new Condition((CPT::Grammar::Condition *)expr);
        default:
            return nullptr;
        }
    }

    IExpr *createValue(CPT::Packrat::IExpr *expr)
    {
        switch (expr->type()) {
        case CPT::CPT_NUMBER:
            return new Constant(((CPT::Grammar::Number *)expr)->get());
        default:
            return nullptr;
        }
    }
} // namespace AST
