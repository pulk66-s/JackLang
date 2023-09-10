#ifndef __CL_CPT_GRAMMAR_CONDITION_CONDITION_HPP__
#define __CL_CPT_GRAMMAR_CONDITION_CONDITION_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT::Grammar
{
    class Condition : public Packrat::IExpr {
    public:
        Condition() {};
        Condition(
            Packrat::IExpr *cond,
            std::vector<Packrat::IExpr *> if_true,
            std::vector<Packrat::IExpr *> if_false
        ): cond(cond), if_true(if_true), if_false(if_false) {};
        enum cpt_type type() { return CPT_COND; };
        struct result *parse(Packrat::Parser &p);
        std::vector<Packrat::IExpr *> getIfTrue() { return if_true; };
        std::vector<Packrat::IExpr *> getIfFalse() { return if_false; };
        Packrat::IExpr *getCond() { return cond; };
    private:
        Packrat::IExpr *cond = nullptr;
        std::vector<Packrat::IExpr *> if_true = {};
        std::vector<Packrat::IExpr *> if_false = {};
    };
} // namespace CPT::Grammar::Cond

#endif
