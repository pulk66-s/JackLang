#ifndef __CL_CPT_GRAMMAR_CONDITION_IF_H__
#define __CL_CPT_GRAMMAR_CONDITION_IF_H__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT::Grammar::Cond
{
    class If : public Packrat::IExpr {
    public:
        If() {};
        If(Packrat::IExpr *cond, std::vector<Packrat::IExpr *> then) : cond(cond), then(then) {};
        enum cpt_type type() { return CPT_COND; };
        struct result *parse(Packrat::Parser &p);
        std::vector<Packrat::IExpr *> get() { return then; };
        Packrat::IExpr *get_cond() { return cond; };
    private:
        Packrat::IExpr *cond = nullptr;
        std::vector<Packrat::IExpr *> then = {};
    };
} // namespace CPT::Grammar::Cond

#endif
