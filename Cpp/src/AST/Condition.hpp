#ifndef __CL_AST_CONDITION_HPP__
#define __CL_AST_CONDITION_HPP__

#include "AST/ASTNamespace.hpp"
#include "AST/Expr.hpp"
#include "AST/Block.hpp"
#include "CPT.hpp"

namespace AST
{
    class Condition : public IExpr {
    public:
        Condition(CPT::Grammar::Condition *cond);
        enum ast_type type() { return ast_type::AST_COND; }
        Block *getTrueBlock() { return trueBlock; };
        Block *getFalseBlock() { return falseBlock; };
        IExpr *getCondition() { return condition; };
    private:
        IExpr *condition = nullptr;
        Block *trueBlock = nullptr;
        Block *falseBlock = nullptr;
    };
} // namespace AST

#endif
